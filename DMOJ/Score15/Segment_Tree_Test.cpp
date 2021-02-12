// https://dmoj.ca/problem/ds3
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
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

template<class T> struct SegTree {

    int size;
    T defVal;
    vec<T> tree;
    T (*op)(T, T);
    
    SegTree (int size, T defVal, T (*op)(T, T))
        : size(size), defVal(defVal), tree(vec<T>(2*size)), op(op) {}

    void build() {

        for (int i = size-1; i>0; --i) {
            tree[i] = op(tree[i<<1], tree[i<<1|1]);
        }

    }
    T query (int l, int r) {

        l += size, r += size+1;
        T res;
        for (res = defVal; l<r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, tree[l++]);
            if (r&1) res = op(res, tree[--r]);
        }
        return res;

    }
    void update (int i, T val) {

        i += size;
        for (tree[i] = val; i>1; i >>= 1) {
            tree[i>>1] = op(tree[i], tree[i^1]);
        }

    }

};

void solve() {

    int n, m; scan(n); scan(m);
    
    SegTree<int> segGCD(n, 0, [](int a, int b) {

        int temp;
        while (a) {
            temp = a;
            a = b%a;
            b = temp;
        }
        return b;

        });
    SegTree<pii> segMin(n, make_pair(1e9+1, 0), [](pii i, pii j) {

        if (i.first==j.first) return make_pair(i.first, i.second+j.second);
        return min(i, j);

        });

    for (int i = n; i<2*n; ++i) {
        scan(segGCD.tree[i]);
        segMin.tree[i] = make_pair(segGCD.tree[i], 1);
    }
    segGCD.build(), segMin.build();

    char c;
    int l, r;
    pii numMin;
    while (m--) {
        c = getchar(); scan(l); scan(r);
        --l, --r;
        switch (c) {
            case 'C':
                ++r;
                segMin.update(l, make_pair(r, 1));
                segGCD.update(l, r);
                break;
            case 'M':
                print(segMin.query(l, r).first);
                break;
            case 'G':
                print(segGCD.query(l, r));
                break;
            case 'Q':
                numMin = segMin.query(l, r);
                print(numMin.first==segGCD.query(l, r)? numMin.second:0);
                break;
            default:
                puts("Something went wrong");
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
