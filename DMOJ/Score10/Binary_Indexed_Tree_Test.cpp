// https://dmoj.ca/problem/ds1
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
#define u_set unordered_set
#define u_map unordered_map
#define pri_q priority_queue
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class B, class E> void scan (B begin, E end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) print(c[i], ' '); putchar('\n'); }

const int mxN = 1e5;

ll get_sum (int i, vector<ll>& BIT) {

    ll sum = 0;
    while (i>0) {
        sum += BIT[i];
        i -= i&-i;
    }
    return sum;

}
void update (int i, ll u, vector<ll>& BIT) {

    while (i<=mxN) {
        BIT[i] += u;
        i += i&-i;
    }

}

void solve() {

    int n, m; scan(n); scan(m);
    vector<ll> sums, less;
    vector<int> v = vector<int>(n+1);
    sums = less = vector<ll>(mxN+1);
    for (int i = 1; i<=n; ++i) {
        scan(v[i]);
        update(i, v[i], sums);
        update(v[i], 1, less);
    }

    int a, b;
    char c;
    while (m--) {
        c = getchar();
        scan(a);

        // Change the a index to b
        if (c=='C') {
            scan(b);
            update(a, b-v[a], sums);
            update(v[a], -1, less);
            update(b, 1, less);
            v[a] = b;

        // Sum from a to b
        } else if (c=='S') {
            scan(b);
            print(get_sum(b, sums)-get_sum(a-1, sums));

        // Output # elements <= a
        } else if (c=='Q') {
            print(get_sum(a, less));
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
