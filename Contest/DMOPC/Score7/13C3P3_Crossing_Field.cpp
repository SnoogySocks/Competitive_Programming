// https://dmoj.ca/problem/dmopc13c3p3
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
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

struct Coordinate {
    int r, c;
    Coordinate (int r = 0, int c = 0) : r(r), c(c) {}
    void setCoordinate (int r, int c) {
        this->r = r;
        this->c = c;
    }
};

const vec<Coordinate> delta {
    { -1, 0 }, { 1, 0 },
    { 0, -1 }, { 0, 1 }
};

enum Map {
    start = 's',
    destination = 'e',
    walkablePath = '.',
    building = 'X'
};

int n, h;
vec<vec<int>> field;
vec<vec<bool>> vis;

void dfs (int r, int c) {

    // Check if the destination has been reached
    if (vis[n-1][n-1]) return;
    vis[r][c] = true;

    for (const auto& [dr, dc]:delta) {
        // Check if the evlevation is valid
        int nextR = r+dr, nextC = c+dc;
        if (vis[n-1][n-1]) break;
        else if (0<=nextR&&nextR<n&&0<=nextC&&nextC<n&&!vis[nextR][nextC]
            && abs(field[r][c]-field[nextR][nextC])<=h)
            dfs(nextR, nextC);
    }

}

void solve() {

    scan(n); scan(h);
    field = vec<vec<int>>(n, vec<int>(n));
    vis = vec<vec<bool>>(n, vec<bool>(n));
    for (int i = 0; i<n; ++i) {
        scan(all(field[i]));
    }

    dfs(0, 0);
    puts(vis[n-1][n-1]?"yes":"no");

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
