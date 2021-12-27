//
// https://dmoj.ca/problem/dpe
// Created by felix on 2021-12-27.
//

#include <bits/stdc++.h>

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
#define fst first
#define snd second

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

const int mxW = 1e9;
const int mxV = 1e5;

/*
 3 8
 3 3
 4 5
 5 6
 */

struct item {
    int w, v;
    item (int w, int v): w(w), v(v) {}
    item (): item(0, 0) {}
};

void solve () {

    int n, w; scan(n, w);
//    vec<item> items(n);
//    int valSum = 0;
//    for (int i = 0; i<n; ++i) {
//        scan(items[i].w, items[i].v);
//        valSum += items[i].v;
//    }
//
//    // dp[v] = the minimum weight to get the value v
//    vec<vec<int>> dp(2, vec<int>(valSum+1, mxW+1));
//    dp[0][0] = dp[1][0] = 0;
//
//    for (const auto& [wi, vi]: items) {
//        for (int v = vi; v<=valSum; ++v) {
//            int val = dp[0][v-vi]+wi;
//            if (val<=mxW) {
//                dp[1][v] = min(dp[1][v], val);
//            }
//        }
//
//        // Move everything that changed in the second row to the first row
//        for (int i = 1; i<=valSum; ++i) {
//            dp[0][i] = min(dp[0][i], dp[1][i]);
//            dp[1][i] = mxW+1;
//        }
//    }
//
//    // Find the greatest value with a valid weight
//    int maxV = 0;
//    for (int v = 1; v<=valSum; ++v) {
//        if (maxV<v && dp[0][v]<=w) {
//            maxV = v;
//        }
//    }
//    print(maxV);

    // Better :(

    // dp[j] = the minimum weight to get a value of v
    vec<int> dp(mxV+1, mxW+1);
    dp[0] = 0;
    for (int i = 0; i<n; ++i) {
        int wi, vi; scan(wi, vi);
        for (int j = mxV; j>=vi; --j) {
            dp[j] = min(dp[j], dp[j-vi]+wi);
        }
    }

    for (int v = mxV; v>=0; --v) {
        if (dp[v]<=w) {
            print(v);
            return;
        }
    }

}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}

