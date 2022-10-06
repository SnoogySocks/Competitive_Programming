// https://www.hackerrank.com/challenges/bfsshortreach/problem
// Octoeber 4, 2022

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
template<class T> void print (vector<T>& v, char&& end = '\n') { for (const T& el: v) print(el, ' '); putchar(end); }
template<class T> void print (vector<T>&& v, char&& end = '\n') { print(v); }

const int unit = 6;

void solve () {

    int n, e; scan(n, e);
    vec<vec<int>> adj(n+1);
    for (int i = 0; i<e; ++i) {
        int u, v; scan(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start; scan(start);

    vec<bool> vis(n+1);
    vec<int> dis(n+1, -1);
    queue<int> q;
    vis[start] = true;
    dis[start] = 0;
    q.push(start);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v: adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }

    for (int i = 1; i<=n; ++i) {
        if (i!=start) {
            print(dis[i]!=-1 ? dis[i]*unit : -1, ' ');
        }
    }
    putchar('\n');

}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q; scan(q);
    while (q--) solve();
    return 0;
}
