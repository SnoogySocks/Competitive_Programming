// https://dmoj.ca/problem/dwite07c4p4
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
    Coordinate (int r = -1, int c = -1) : r(r), c(c) {}
    void setCoordinate (int r, int c) {
        this->r = r;
        this->c = c;
    }
    bool isUnitialized() {
        return r==-1&&c==-1;
    }
};

const vec<Coordinate> delta {
    { -1, -1 }, { -1, 0 }, { -1, 1 },
    { 0, -1 }, { 0, 0 }, { 0, 1 },
    { 1, -1 }, { 1, 0 }, { 1, 1 }
};

enum Maze {
    emptySpace = '.',
    wall = '#',
    target = 'X',
    unvisited = -1
};

const int mxData = 5;
const int mxN = 10;
vec<vec<char>> maze(mxN, vec<char>(mxN));
vec<vec<int>> dis(mxN, vec<int>(mxN));

void solve() {

    vec<Coordinate> targets;
    
    for (int i = 0; i<mxN; ++i) {
        for (int j = 0; j<mxN; ++j) {
            maze[i][j] = getchar();
            dis[i][j] = unvisited;
            if (maze[i][j]==target)
                targets.emplace_back(i, j);
        }
        getchar();
    }

    queue<Coordinate> q;
    q.emplace(targets[0]);
    dis[targets[0].r][targets[0].c] = 0;

    while (dis[targets[1].r][targets[1].c]==-1) {
        auto [curr, curc] = q.front();
        q.pop();
        for (const auto& [dr, dc]:delta) {
            // If r and c are within bounds and unvisited then
            int r = curr+dr, c = curc+dc;
            if (0<=r&&r<mxN&&0<=c&&c<mxN&&dis[r][c]==unvisited&&maze[r][c]!=wall) {
                dis[r][c] = dis[curr][curc]+1;
                q.emplace(r, c);
            }
        }
    }
    print(dis[targets[1].r][targets[1].c]);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while (t--) solve();
#else
    vec<char> buffer(mxN);
    for (int i = 0; i<mxData; ++i) {
        solve();
        scan(buffer);
    }
#endif
    return 0;
}
#endif
