// https://dmoj.ca/problem/ichb2017p3
// 01/2021

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) print(c[i], ' '); putchar('\n'); }

int n, q;
vector<uint> seg;

void build() {
    for (int i = n-1; i>0; --i) {
        seg[i] = seg[i<<1]&seg[i<<1|1];
    }
}

void update (uint i, uint val) {
    i += n;
    for (seg[i] = val; i>1; i >>= 1) {
        seg[i>>1] = seg[i]&seg[i^1];
    }
}

uint andto (uint l, uint r) {
    l += n, r += n;
    uint res;
    for (res = seg[l]; l<r; l >>= 1, r >>= 1) {
        if (l&1) res &= seg[l++];
        if (r&1) res &= seg[--r];
    }
    return res;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    
    scan(n); scan(q);
    seg = vector<uint>(2*n);
    scan(seg.begin()+n, seg.end());
    build();

    char c;
    uint x, y, z;
    while (q--) {
        c = getchar(); scan(x); scan(y);
        if (c=='U') {
            update(x-1, y);
        } else if (c=='Q') {
            scan(z);
            print(andto(x-1, y)&z);
        }
    }
    
    return 0;
    
}
