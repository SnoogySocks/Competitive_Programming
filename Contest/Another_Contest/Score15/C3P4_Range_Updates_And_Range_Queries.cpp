// https://dmoj.ca/problem/acc3p4
// 03/2021

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
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& fac, U b) { if (fac<b) fac = b; }
template<class T, class U> static inline void amin (T& fac, U b) { if (fac>b) fac = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { c.clear(); char buf; do buf = getchar(); while (buf<'!'||'~'<buf); for (; buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); c.push_back('\0'); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

class SegmentTree {

private:


    static const ll empty = -1;
    struct begin {
        int fac, a;
        begin () : fac(empty), a(empty) {}
        begin (int fac, int a) : fac(fac), a(a) {}
    };

    int arrLen, height;
    std::vector<ll> tree;
    std::vector<begin> lazy;


    // (Only called for inner nodes)
    // Refresh the inner node
    void refresh (int node) {
        tree[node] = tree[node<<1]+tree[node<<1|1];
    }

    // Assign val to the current node
    void assign (int node, int fac, int a, int nodeRange) {

        tree[node] += fac*sumSeries(a, nodeRange);

        // Remember to update node's children
        if (node<arrLen)
            lazy[node] = begin(fac, a);

    }

    ll sumSeries (ll a, ll n) {
        return n*(2ll*a+n-1ll)/2ll;
    }

public:

    SegmentTree (int arrLen)
        : arrLen(arrLen), height(ceil(log2(arrLen))),
        tree(std::vector<ll>(2*arrLen)),
        lazy(std::vector<begin>(arrLen)) {}

    void propagate (int node) {

        // Increment to the leaf node counterpart
        node += arrLen;

        // Traverse from root height to leaf height
        // (rootHeight = height, leafHeight = 1)
        for (int curHeight = height; curHeight>=1; --curHeight) {

            int curNode = node>>curHeight;
            int childRange = 1<<(curHeight-1);

            // Propagate the pending changes if any to curNode's children
            if (lazy[curNode].a==empty) continue;
            assign(curNode<<1,   lazy[curNode].fac, lazy[curNode].a, childRange);
            assign(curNode<<1|1, lazy[curNode].fac, lazy[curNode].a+childRange, childRange);
            lazy[curNode] = begin();

        }

    }

    // Update all [l, r] to val
    void update (int l, int r, int fac) {

        // Propagate pending changes up to the leaf nodes
        propagate(l);
        propagate(r);

        int lNumChanged, rNumChanged;
        lNumChanged = rNumChanged = 0;
        l += arrLen, r += arrLen;
        int nodeRange;

        for (nodeRange = 1; l<=r; l >>= 1, r >>= 1, nodeRange <<= 1) {

            // If a change was made to l-1/r+1's 
            // children, make the change to the 
            // parent as well
            if (lNumChanged) refresh(l-1);    // l-1 => previous l parent (or l's sibling)
            if (rNumChanged) refresh(r+1);    // r+1 => previous r parent (or r's sibling)

            if ((l&1)==1) {
                assign(l++, fac, lNumChanged, nodeRange);
                lNumChanged += nodeRange;
            }
            if ((r&1)==0) {
                assign(r--, fac, r-l+1-rNumChanged, nodeRange);
                rNumChanged += nodeRange;
            }

        }

        // Refresh to the root node
        for (--l, ++r; nodeRange<=1<<height; l >>= 1, r >>= 1, nodeRange <<= 1) {
            if (lNumChanged)
                refresh(l);
            if (rNumChanged&&(!lNumChanged||l!=r))
                refresh(r);
        }

    }

    // Quary from range [l, r]
    ll query (int l, int r) {

        // Propagate pending changes up to the leaf nodes
        propagate(l);
        propagate(r);

        l += arrLen, r += arrLen;
        ll res;
        for (res = 0; l<=r; l >>= 1, r >>= 1) {
            if ((l&1)==1) res += tree[l++];
            if ((r&1)==0) res += tree[r--];
        }
        return res;

    }

    ll& operator[] (int i) {
        return tree[i+arrLen];
    }

};

void solve() {

    int n, q; scan(n); scan(q);
    SegmentTree seg(n);

    while (q--) {

        int q, l, r; scan(q); scan(l); scan(r);
        --l, --r;
        
        // Increment
        if (q==1) {

            int fac; scan(fac);
            
            // Each increment is an arithmetic series multiplied by a
            // Formula: n(2a+n-1)/2
            seg.update(l, r, fac);

        // Sum range
        } else if (q==2) {
            print(seg.query(l, r));
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
