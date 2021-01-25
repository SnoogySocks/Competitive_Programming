// https://dmoj.ca/problem/ac19p5
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
typedef pair<int, int> pii;
#define u_set unordered_set
#define u_map unordered_map
#define pri_q priority_queue
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class B, class E> void scan (B begin, E end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) print(c[i], ' '); }

vector<vector<int>> mx;
vector<vector<int>> dis;

vector<pii> adjs (int r, int c) {
    return { {r-1, c}, {r+1, c}, {r, c-1}, {r, c+1} };
}

int dfs (int r, int c) {

    int& cur = dis[r][c];
    if (cur!=-1) return cur;

    cur = 0;
    for (pii adj:adjs(r, c)) {
        if (mx[r][c]<mx[adj.first][adj.second])
            amax(cur, dfs(adj.first, adj.second)+1);
    }
    return cur;

}

void solve() {

    int n; scan(n);
    // dp[r][c] = max path to get to [r][c]
    mx = vector<vector<int>>(n+2, vector<int>(n+2));
    dis = vector<vector<int>>(n+2, vector<int>(n+2, -1));
    for (int r = 1; r<=n; ++r) {
        for (int c = 1; c<=n; ++c) {
            scan(mx[r][c]);
        }
    }
    
    int ans = 0;
    for (int r = 1; r<=n; ++r) {
        for (int c = 1; c<=n; ++c) {
            amax(ans, dfs(r, c));
        }
    }

    print(ans);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while (t--) solve();
#else
    solve();
#endif
    return 0;
}
