// https://dmoj.ca/problem/dmopc13c1p4
// 03/2021

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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); for (int i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct coordinate {
    int r, c;
    coordinate() : r(0), c(0) {}
    coordinate (int r, int c) : r(r), c(c) {}
};

const int mxN = 50;
vector<vector<char>> floorMp(mxN, vector<char>(mxN));
vector<vector<int>> dis(mxN, vector<int>(mxN));

void solve() {

    int l, w; scan(l); scan(w);
    coordinate washroom;
    queue<coordinate> q;

    for (int r = 0; r<w; ++r) {
        for (int c = 0; c<l; ++c) {
            floorMp[r][c] = getchar();
            dis[r][c] = 0;
            if (floorMp[r][c]=='C') {
                floorMp[r][c] = 'X';
                q.emplace(r, c);
            } else if (floorMp[r][c]=='W') {
                washroom = coordinate(r, c);
            }
        }
        getchar();
    }

    bool yes = false;
    while (q.size()&&!yes) {
        coordinate coord = q.front(); q.pop();
        for (int i = 0; i<4&&!yes; ++i) {
            int r = coord.r+dr[i];
            int c = coord.c+dc[i];
            if (r<0||w<=r||c<0||l<=c||floorMp[r][c]=='X') continue;
            else if (floorMp[r][c]=='W') yes = true;

            floorMp[r][c] = 'X';
            dis[r][c] = dis[coord.r][coord.c]+1;
            q.emplace(r, c);
        }
    }

    puts(dis[washroom.r][washroom.c]>=60||floorMp[washroom.r][washroom.c]!='X'?"#notworth":&to_string(dis[washroom.r][washroom.c])[0]);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 1
    int t; scan(t); while (t--) solve();
#else
    solve();
#endif
    return 0;
}
#endif
