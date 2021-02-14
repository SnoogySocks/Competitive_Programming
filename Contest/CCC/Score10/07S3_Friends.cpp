// https://dmoj.ca/problem/ccc07s3
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

const int mxN = 9999;

vec<int> adj, vis, dis;
vec<uset<int>> circles;

void solve() {

    int n; scan(n);
    adj = vis = dis = vec<int>(mxN+1);
    int a, b;
    for (int i = 0; i<n; ++i) {
        scan(a); scan(b);
        adj[a] = b;
    }
    
    circles.reserve(n);
    for (int i = 1; i<=mxN; ++i) {
        if (adj[i]==0||vis[i]) continue;
        circles.push_back(uset<int>());
        for (int j = i; vis[j]<=1; j = adj[j]) {
            if (vis[adj[j]]==0) {
                vis[j] = 1;
                dis[adj[j]] = dis[j]+1;
            } else if (vis[adj[j]]>=1) {
                vis[j] = 2;
                circles.back().insert(j);
            }
        }
    }

    bool yes;
    int i;
    while (true) {
        scan(a); scan(b);
        if (a==0) break;

        yes = true;
        for (i = 0; i<circles.size()&&yes; ++i) {
            if (circles[i].count(a)&&circles[i].count(b)) {
                yes = false;
            }
        }
        if (yes) {
            puts("No");
        } else {
            i = circles[i-1].size();
            printf("Yes %d\n", (i-dis[a]+dis[b])%i-1);
        }
    }

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
