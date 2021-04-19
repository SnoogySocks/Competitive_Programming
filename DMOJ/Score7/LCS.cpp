// https://dmoj.ca/problem/dpf
// 05/2021

#if 1
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

using namespace std; typedef unsigned int uint; typedef long long ll; typedef unsigned long long ull; typedef long double dl; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); }
template<class T> static void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; } template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); } template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); } template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
template<class T> static void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (vector<T>& v) { for (T el:v) print(el, ' '); putchar('\n'); }
template<class T> void print (vector<T>&& v) { print(v); }

const int mxN = 3000;

/*
abracadabra
avadakedavra
a a a d a  r  a
1 4 6 7 8 10 11
1 3 5 8 9 11 12
dara
*/

void solve() {

    vec<char> a, b;
    a = b = vec<char>(1);
    a.reserve(mxN+1); b.reserve(mxN+1);
    scan(a, b);

    // Max length with the first i and j characters from a and b respectively
    vec<vec<int>> dp(a.size(), vec<int>(b.size()));
    for (int i = 1; i<a.size(); ++i) {
        for (int j = 1; j<b.size(); ++j) {
            // Max length with the first i-1 and j-1 characters
            if (a[i]==b[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int apnt = a.size()-1;
    int bpnt = b.size()-1;
    vec<char> sub(dp[apnt][bpnt]+1);
    for (int k = dp[apnt][bpnt]-1; k>=0; --k) {
        while (dp[apnt][bpnt]==dp[apnt-1][bpnt]) --apnt;
        while (dp[apnt][bpnt]==dp[apnt][bpnt-1]) --bpnt;
        sub[k] = a[apnt];
        --apnt;
        --bpnt;
    }

    puts(&sub[0]);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
