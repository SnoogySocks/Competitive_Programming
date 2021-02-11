// https://dmoj.ca/problem/ccc03s3
// 02/2021

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
void scan (vector<char>& c, const char&& escape = ' ') { c.clear(); char buf; do buf = getchar(); while (buf<'!'||'~'<buf); for (; buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); c.push_back('\0'); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

/*
105
14
16
IIIIIIIIIIIIIIII
I......I.......I
I......III.....I
I........I.....I
I........IIIIIII
IIIIIIIIII.....I
I.I......I.....I
III..III.I.....I
I....I.IIIII...I
I....I.....III.I
I....I.......I.I
I....I.....III.I
I....I.....I...I
IIIIIIIIIIIIIIII
*/

vec<vec<bool>> vis;
vec<int> rmArea;

void dfs (int i, int j, int curRm) {

    if (vis[i][j]) return;
    vis[i][j] = true;
    ++rmArea[curRm];
    dfs(i, j+1, curRm);
    dfs(i, j-1, curRm);
    dfs(i+1, j, curRm);
    dfs(i-1, j, curRm);

}

void solve() {

    int r, c, nwood; scan(nwood); scan(r); scan(c);
    vis = vec<vec<bool>>(r+2, vec<bool>(c+2));
    fill(all(vis[0]), true);
    fill(all(vis[r+1]), true);

    vec<char> s; s.reserve(r);
    for (int i = 1; i<=r; ++i) {
        scan(s);
        vis[i][0] = true;
        for (int j = 0; j<c; ++j) {
            vis[i][j+1] = s[j]=='I';
        }
        vis[i][c+1] = true;
    }

    for (int i = 1; i<=r; ++i) {
        for (int j = 1; j<=c; ++j) {
            if (!vis[i][j]) {
                rmArea.push_back(0);
                dfs(i, j, rmArea.size()-1);
            }
        }
    }

    sort(all(rmArea), greater<int>());
    int i;
    for (i = 0; i<rmArea.size()&&nwood-rmArea[i]>=0; nwood -= rmArea[i++]);
    if (i!=1) printf("%d rooms, %d square metre(s) left over\n", i, nwood);
    else printf("1 room, %d square metre(s) left over\n", nwood);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while(t--) solve();
#else
    solve();
#endif
    return 0; 
}
