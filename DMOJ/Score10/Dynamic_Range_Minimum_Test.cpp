// https://dmoj.ca/problem/segtree
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

const int mxN = 1e6;

int len;
vec<int> seg;

void update (int i, int val) {

    i += len;
    for (seg[i] = val; i>1; i >>= 1) {
        seg[i>>1] = min(seg[i], seg[i^1]);
    }

}

int query (int l, int r) {

    l += len, r += len+1;
    
    int lowest;
    for (lowest = mxN; l<r; l >>= 1, r >>= 1) {
        if (l&1) amin(lowest, seg[l++]);
        if (r&1) amin(lowest, seg[--r]);
    }
    return lowest;

}

void solve() {

    int n, q; scan(n); scan(q);
    len = n;
    seg = vec<int>(2*len);
    scan(seg.begin()+len, seg.end());
    for (int i = len-1; i>=1; --i) {
        seg[i] = min(seg[i<<1], seg[i<<1|1]);
    }

    char c;
    int i, j;
    while (q--) {
        c = getchar(); scan(i); scan(j);
        if (c=='Q') {
            print(query(i, j));
        } else if (c=='M') {
            update(i, j);
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
