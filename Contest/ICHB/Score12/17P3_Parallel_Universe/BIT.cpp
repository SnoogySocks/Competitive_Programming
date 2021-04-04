// https://dmoj.ca/problem/ichb2017p3
// 01/2021

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
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) print(c[i], ' '); putchar('\n'); }

const int mxN = 32;

struct BIT {
    
    /*
        bit[i][j] = sum of previous set bits in the original array, but in a BIT
        Example:
        1 0 1 0 = 10
        1 0 1 1 = 11
        0 1 1 0 = 6
        Turns into
        1 0 1 0
        2 1 2 1
        2 1 3 1
    /*
    vector<vector<int>> bit;
    BIT (int size) : bit(vector<vector<int>>(size, vector<int>(mxN))) {}
    BIT (vector<ll>& v) : bit(vector<vector<int>>(v.size()+1, vector<int>(mxN))) {
        for (int i = 1; i<v.size(); ++i) update(i, v[i]);
    }
    
    // Sum the set binary digits into bit
    void addiv (int i, ll n) {
        ll neg = (n>=0)?1:-1;
        n *= neg;
        for (int j = 0; n>0; ++j, n >>= 1) 
            bit[i][j] += neg*(n&1);
    }
    // 
    void sum (int i, vector<int>& s) {
        s = vector<int>(mxN);
        while (i>0) {
            // Get sum of the set binary digits
            for (int j = 0; j<mxN; ++j) s[j] += bit[i][j];
            i -= i&-i;
        }
    }
    // Update bit
    void update (int i, ll v) {
        while (i<bit.size()) {
            addiv(i, v);
            i += i&-i;
        }
    }

};

void solve() {

    int n, q; scan(n); scan(q);
    vector<ll> v(n+1);
    for (int i = 1; i<=n; ++i) {
        scan(v[i]);
    }
    BIT bit(v);
    
    int x, y;
    ll z;
    char c;
    vector<int> s1, s2;
    while (q--) {
        c = getchar(); scan(x);
        if (c=='U') {
            scan(z);
            // Remove v[x] from the tree and replace it with z
            bit.update(x, -v[x]);
            bit.update(x, z);
            v[x] = z;
        } else if (c=='Q') {
            scan(y); scan(z);
            bit.sum(x-1, s1); bit.sum(y, s2);
            ll val = 0;
            for (int i = 0; i<mxN; ++i) {
                // Bits in an interval will only be set if the difference
                // of set bits equals the difference in the interval
                val += (ll)(s2[i]-s1[i]==y-x+1)<<i;
            }
            print(z&val);
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
