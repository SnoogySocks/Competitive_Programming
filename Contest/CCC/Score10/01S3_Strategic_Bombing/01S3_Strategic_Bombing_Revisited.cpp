// https://dmoj.ca/problem/ccc01s3
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
#include <list>
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

const int mxN = 26;
vec<list<char>> adjs(mxN);
vec<int> parent(mxN, -1), discDepth(mxN), earliestDiscDepth(mxN);
vec<bool> vis(mxN);
int ans, depth;

void dfs (int u) {

    vis[u] = true;
    discDepth[u] = earliestDiscDepth[u] = ++depth;

    for (int v:adjs[u]) {

        if (!vis[v]) {
            
            parent[v] = u;
            dfs(v);

            amin(earliestDiscDepth[u], earliestDiscDepth[v]);

            if (earliestDiscDepth[v]>discDepth[u])
                printf("%c%c\n", u+'A', v+'A'), ++ans;

        } else if (v!=parent[u]) 
            amin(earliestDiscDepth[u], discDepth[v]);

    }
    
}

void solve() {

    vec<char> a; a.reserve(3);

    while (true) {
        scan(a);
        if (a[0]=='*') break;
        adjs[a[0]-'A'].push_back(a[1]-'A');
        adjs[a[1]-'A'].push_back(a[0]-'A');
    }

    depth = ans = 0;
    dfs(0);

    printf("There are %d disconnecting roads.\n", ans);

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
