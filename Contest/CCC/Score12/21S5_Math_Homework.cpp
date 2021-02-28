// https://dmoj.ca/problem/ccc21s5
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

int gcd (int a, int b) {
    ll temp;
    while (a!=0) {
        temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

int lcm (int a, int b) {
    return a*b/gcd(a, b);
}

struct SegmentTree {
    int len;
    vec<int> tree;
    
    SegmentTree (int len) : len(len), tree(vec<int>(2*len)) {}
    
    void build() {
        for (int i = len-1; i>=1; --i)
            tree[i] = gcd(tree[i<<1], tree[i<<1|1]);
    }
    
    int query (int l, int r) {
        l += len, r += len;
        int theGcd;
        for (theGcd = 0; l<=r; l >>= 1, r >>= 1) {
            if (l%2==1) theGcd = gcd(theGcd, tree[l++]);
            if (r%2==0) theGcd = gcd(theGcd, tree[r--]);
        }
        return theGcd;
    }
    int& operator[] (int i) {
        return tree[i+len];
    }
};

/*
2 2
1 2 2
2 2 6

2 2
1 2 2
2 2 5

4 3
1 4 2
2 4 4
1 2 6

0   0  0   0   0
2   0  0   0  -2
2   4  0   0  -2,-4
2,6 4 -6   0  -2,-4
12 48  8   8   1
6  12  4   4   1
*/

const int mxN = 1<<4;

void solve() {

    /*
        Find the factor that cancels out the current number
        from the gcd number
        1. Create a product array
        2. find the lcm, then the gcd of the last element and the current element in the product

        After, take the array multiply on everything

        Save the queries, then test the array with the same queries
        to see if everything still matches. If not, print Impossible
    */

    int n, q; scan(n); scan(q);
    vec<vec<int>> nums(n+1, vec<int>(mxN+1)); // Negatives mean division

    SegmentTree seg(n);
    vec<vec<int>> queries(q, vec<int>(3));
    for (vec<int>& query: queries) {
        scan(all(query));
        --query[0], --query[1];
        ++nums[query[0]][query[2]];
        --nums[query[1]+1][query[2]];
    }

    // Find the product and lcm at the same time
    for (int i = 0; i<n; ++i) {

        seg[i] = 1;
        for (int j = mxN; j>=1; --j) {                  // Find the gcd at the current position
            if (i!=0) nums[i][j] += nums[i-1][j];       // Multiply/divide the current number
            if (nums[i][j]) seg[i] = lcm(seg[i], j);    // Find gcd of remainings
        }
        
    }
    seg.build();

    for (vec<int>& query: queries) {
        if (seg.query(query[0], query[1])!=query[2]) {
            puts("Impossible");
            return;
        }
    }
    for (int i = 0; i<n; ++i) {
        print(seg[i], ' ');
    }
    putchar('\n');

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
