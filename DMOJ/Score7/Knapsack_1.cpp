//
// https://dmoj.ca/problem/dpd
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

/*
 6 15
 6 5
 5 6
 6 4
 6 6
 3 5
 7 2
 */

void solve () {

    int n, w; scan(n, w);
//    vec<pair<int, ll>> items(n);
//    for (int i = 0; i<n; ++i) {
//        scan(items[i].fst, items[i].snd);   // fst = weight, snd = value
//    }

    // dp[i].fst = max value across the whole thing
    // dp[i].snd[w] = max value using the ith item to make a weight of w
//    vec<pair<ll, vec<ll>>> dp(n, make_pair(0, vec<ll>(w+1)));
//    for (int i = 0; i<n; ++i) {
//        for (int cw = items[i].fst; cw<=w; ++cw) {
//            // If last added item was not the current item then add it
//            int prevW = cw-items[i].fst;
//            ll val = dp[prevW].fst+items[i].snd;
//            if (dp[cw].fst<val) {
//                dp[cw] = make_pair(val, i);
//            }
//        }
//    }

    // dp[i].fst = max value with a weight of i
    // dp[i].snd = last item added to get weight i
    vec<ll> dp(w+1);
    vec<pair<int, ll>> cache; cache.reserve(w+1);
    for (int i = 0; i<n; ++i) {
        int w0;
        ll v;
        scan(w0, v);

        for (int cw = w0; cw<=w; ++cw) {
            // If last added item was not the current item then add it
            int prevW = cw-w0;
            ll val = dp[prevW]+v;
            if (dp[cw]<val) {
                cache.emplace_back(cw, val);
            }
        }

        for (auto [w1, v1]: cache) {
            dp[w1] = v1;
        }
        cache.clear();
    }

    print(*max_element(all(dp)));

    // Better :(
//    vec<ll> dp(w+1);
//    for (int i = 0; i<n; ++i) {
//        int w0;
//        ll v;
//        scan(w0, v);
//        for (int cw = w; cw>=w0; --cw) {
//            dp[cw] = max(dp[cw], dp[cw-w0]+v);
//        }
//    }
//
//    print(dp[w]);

}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}

