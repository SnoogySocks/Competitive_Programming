// https://dmoj.ca/problem/gfssoc2j5
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

//int len;
//vec<pii> tree;
//
//pii op (pii a, pii b) {
//    if (a.first==b.first) return make_pair(a.first, a.second+b.second);
//    return max(a, b);
//}
//
//pii query (int l, int r) {
//    l += len, r += len;
//    pii maximum;
//    for (maximum = make_pair(0, 0); l<=r; l >>= 1, r >>= 1) {
//        if (l%2==1) maximum = op(maximum, tree[l++]);
//        if (r%2==0) maximum = op(maximum, tree[r--]);
//    }
//    return maximum;
//}
//
//void solve() {
//
//    int n, q; scan(n); scan(q);
//    len = n;
//    tree = vec<pii>(2*len); 
//    for (int i = 0; i<n; ++i) {
//        scan(tree[i+n].first);
//        tree[i+n].second = 1;
//    }
//    for (int i = len-1; i>=1; --i) {
//        tree[i] = op(tree[i<<1], tree[i<<1|1]);
//    }
//
//    int a, b;
//    pii left, right, maximum;
//    while (q--) {
//        scan(a); scan(b);
//        --a, --b;
//        left = query(0, a-1);
//        right = query(b+1, len-1);
//        maximum = op(left, right);
//        printf("%d %d\n", maximum.first, maximum.second);
//    }
//
//}

const int mxN = 10;

void solve() {

    int n, q; scan(n); scan(q);
    vec<vec<int>> ratings(mxN+1, vec<int>(n+1));
    
    for (int i = 1; i<=n; ++i) {
        int rating; scan(rating);
        ratings[rating][i] = 1;
    }
    for (int i = 1; i<=mxN; ++i) {
        for (int j = 2; j<=n; ++j) {
            ratings[i][j] += ratings[i][j-1];
        }
    }
    while (q--) {
        int a, b; scan(a); scan(b);
        for (int i = mxN; i>=1; --i) {
            int left, right;
            left = ratings[i][a-1];
            right = ratings[i][n]-ratings[i][b];
            if (left!=0||right!=0) {
                printf("%d %d\n", i, left+right);
                break;
            }
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
