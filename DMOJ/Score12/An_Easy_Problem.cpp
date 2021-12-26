// https://dmoj.ca/problem/ccoprep16c2q2
// 26/12/2021

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <climits>
#include <cassert>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)
#define square(x) ((x)*(x))

template<class T> static void scan (T& e) { e = 0; bool neg = false; char c = getchar(); for (; c<'0' || '9'<c; c = getchar()) if (c=='-') neg = true; for (; '0'<=c && c<='9'; c = getchar()) e = (e<<3)+(e<<1)+(c&15); if (neg) e *= -1; }
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!' || '~'<buf); int i; for (i = 0; buf!='\n' && buf!=escape; buf = getchar()) c[i++] = buf; }
template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); }
template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); }
template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void print (T e, char&& end = '\n') { bool neg = false; if (e<0) neg = true, e *= -1; char snum[65]; int i = 0; do { snum[i++] = e%10+'0'; e /= 10; } while (e); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
static void print (char e, char&& end = '\n') { putchar(e); putchar(end); }
template<class T> void print (const vector<T>& v, char&& end = '\n') { for (const T& el: v) print(el, ' '); putchar(end); }
template<class T> void print (const vector<T>&& v, char&& end = '\n') { print(v); }

const int mxN = 30; // ceil(log2(10^9))
/*
 100
 5 5 15 15 3 16 2 15 11 12
 0 14 3 11 14 14 16 9 16 10
 3 0 5 7 3 6 9 16 1 10
 9 5 12 12 14 13 7 11 7 0
 11 6 0 9 10 1 9 6 7 14
 1 6 11 1 9 8 11 1 6 12
 14 9 8 14 13 1 3 0 10 1
 5 14 1 13 1 0 5 7 14 9
 12 2 2 9 14 15 13 7 5 10
 8 10 9 13 7 5 10 8 10 9
 15 14 5 3 15 10 12

 55
 10
 5 5 1 7 1 1 5 2 7 6

 5
 1 1 2 3 3

 4
 2 2 1 3
 3 2

 4
 2 2 3 0
 */

int other (const vec<pair<int, vec<int>>>& v, int n) {
    vec<int> dp(n, 1);
    for (int i = 0; i<v.size(); ++i) {
        for (int j = i-1; j>=0; --j) {
            if (v[i].first&v[j].first) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(all(dp));
}

int bad (const vec<pair<int, vec<int>>>& v, int n) {

    vec<pair<int, vec<int>>> arr(all(v));
    umap<int, vec<int>> cntDigits; cntDigits.reserve(mxN);
//    for (int i = 0; i<mxN; ++i) {
//        cntDigits[1<<i] = vec<int>();
//    }

    for (int i = 0; i<n; ++i) {
        int a = arr[i].first;
        while (a>0) {
            int bit = a&-a;
            if (cntDigits.count(bit)==0) {
                cntDigits[bit] = vec<int>();
            }
            cntDigits[bit].push_back(i);
            arr[i].second.push_back((int) cntDigits[bit].size()-1); // Map arr[i] to an index in cntDigits
            a -= bit;
        }
    }

    // dp[i] = length of largest subsequence with first i elements which must include itself
    vec<int> dp(n, 1);

    for (int i = 0; i<n; ++i) {
        int a = arr[i].first;
        for (int j: arr[i].second) {
            if (j==0) continue;     // When it's the first number with that bit then skip
            dp[i] = max(dp[i], dp[cntDigits[a&-a][j-1]]+1);
            a -= a&-a;
        }
    }

    return *max_element(all(dp));
}

void solve () {

    int n; scan(n);
    vec<pair<int, vec<int>>> arr(n);

    // Map all the numbers to an index in cntDigits. Then maximum valid number would be
    // the number directly before it in the list, mapped to the lowest set bit.
    umap<int, vec<int>> cntDigits; cntDigits.reserve(mxN);
//    for (int i = 0; i<mxN; ++i) {
//        cntDigits[1<<i] = vec<int>();
//    }

    for (int i = 0; i<n; ++i) {
        scan(arr[i].first);
        int a = arr[i].first;
        while (a>0) {
            int bit = a&-a;
            if (cntDigits.count(bit)==0) {
                cntDigits[bit] = vec<int>();
            }
            cntDigits[bit].push_back(i);
            arr[i].second.push_back((int) cntDigits[bit].size()-1); // Map arr[i] to an index in cntDigits
            a -= bit;
        }
    }
//    print(other(arr, n));

    // dp[i] = length of largest subsequence with first i elements which must include itself
    vec<int> dp(n, 1);

    for (int i = 0; i<n; ++i) {
        int a = arr[i].first;
        for (int j: arr[i].second) {
            if (j!=0) {     // When it's the first number with that bit then skip
                dp[i] = max(dp[i], dp[cntDigits[a&-a][j-1]]+1);
            }
            a -= a&-a;
        }
    }

    print(*max_element(all(dp)));

}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    // Generate random test cases of size 10
//    int n = 4;
//    vec<pair<int, vec<int>>> test(n);
//    int res1, res2;
//    res1 = res2 = 0;
//    while (res1==res2) {
//        for (int i = 0; i<n; ++i) {
//            test[i].first = rand()%n;
//        }
//        res1 = other(test, n);
//        res2 = bad(test, n);
//    }
//
//    print(n);
//    for (auto [f, s]: test) {
//        print(f, ' ');
//    }
//    putchar('\n');
//
//    printf("%d %d", res1, res2);

    return 0;
}

