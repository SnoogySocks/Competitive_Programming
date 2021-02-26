// https://dmoj.ca/problem/dmopc19c2p3
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
#include <bitset>

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

const int mxN = 3e5;
const int mxG = 20;

struct SegmentTree {

    int len;
    vec<int> tree;

    SegmentTree (vec<int>& v, int g) : len(v.size()), tree(vec<int>(2*len)) {
        // Copy the contents
        for (int i = 0; i<len; ++i) {
            if (v[i]==g) tree[i+len] = 1;
        }
        build();
    }
    
    void build() {
        for (int i = len-1; i>=1; --i) {
            tree[i] = tree[i<<1]+tree[i<<1|1];
        }
    }
    void update (int i, int val) {
        tree[i += len] = val;
        for (i >>= 1; i>=1; i >>= 1)
            tree[i] = tree[i<<1]+tree[i<<1|1];
    }
    int query (int l, int r) {
        l += len, r += len;
        int sum;
        for (sum = 0; l<=r; l >>= 1, r >>= 1) {
            if (l%2==1) sum += tree[l++];
            if (r%2==0) sum += tree[r--];
        }
        return sum;
    }

};

vec<int> v;

struct BITree {

    int len;
    int bit[mxN+1];

    BITree (int g) : len(v.size()), bit() {
        for (int i = 1; i<=len; ++i) {
            if (v[i-1]==g) bit[i] += 1;
            if (i+lsb(i)<=len) bit[i+lsb(i)] += bit[i];
        }
    }

    void update (int i, int val) {
        for (; i<=len; i += lsb(i))
            bit[i] += val;
    }
    int getSum (int i) {
        int sum;
        for (sum = 0; i>0; i -= lsb(i))
            sum += bit[i];
        return sum;
    }
    int query (int l, int r) {
        return getSum(r)-getSum(l-1);
    }

private:
    inline int lsb (int i) {
        return i&-i;
    }

};

void solve() {

    int n, m; scan(n); scan(m);
    v = vec<int>(n); scan(all(v));
    
    // Create a data structure representing the goodness
    // Each index contains BITree over the array
    // but its index will represent the goondess value
    // that it will take care of
    vec<BITree> goodnesses; goodnesses.reserve(mxG+1);
    for (int i = 0; i<=mxG; ++i) {
        goodnesses.emplace_back(i);
    }

    vec<int> q(4);
    while (m--) {
        scan(q.begin(), q.end()-1);
        if (q[0]==1) {
            goodnesses[v[q[1]-1]].update(q[1], -1);
            goodnesses[q[2]].update(q[1], 1);
            v[q[1]-1] = q[2];
        } else if (q[0]==2) {
            scan(q[3]);
            int maxGoodness = mxG;
            for (int maxCnt = 0; maxCnt<q[3]; --maxGoodness)
                maxCnt += goodnesses[maxGoodness].query(q[1], q[2]);
            print(maxGoodness+1);
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
