// https://dmoj.ca/problem/anoisyclass
// 01/2021

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
#define u_set unordered_set
#define u_map unordered_map
#define pri_q priority_queue
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class B, class E> void scan (B begin, E end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) print(c[i]); }

int n, m;
vector<vector<int>> adj;
vector<int> vis;

bool dfs (int u) {

    vis[u] = 1;
    for (int v:adj[u]) if (vis[v]==1||vis[v]==0&&dfs(v)) return true;
    vis[u] = 2;
    return false;

}

void solve() {

    for (int i = 1; i<=n; ++i) {
        if (dfs(i)) {
            puts("N");
            return;
        }
    }
    puts("Y");

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while(t--) solve();
#else
    scan(n); scan(m);
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1);
    int a, b;
    for (int i = 0; i<m; ++i) {
        scan(a); scan(b);
        adj[a].push_back(b);
    }

    solve();
#endif
    return 0; 
}
