#include <bits/stdc++.h>

using namespace std;

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T&n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class C, class S> void scan (C& c, S size) { for (S i = 0; i<size; i++) scan(c[i]); }
void scan (char* c, int size, char&& escape = '\n') { if (c[0]) memset(c, 0, size); char buf; do buf = getchar(); while ((buf<'0'||'9'<buf)&&(buf<'A'||'Z'<buf)&&(buf<'a'||'z'<buf)); for (int i = 0; buf!=escape; buf = getchar())c[i++] = buf; if (c[size-1]) throw out_of_range("STRING SIZE TOO SMALL"); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) cout<<c[i]<<'\n'; }

const int mxN = 500;
const int mxM = 1e6;
int a[mxN+1][mxN+1]{};
int dp[mxN+1][mxN+1]{}; // Indexes correspond to r and c. Value is the distance traveled

int main() {
    int r, c;
    scan(r),scan(c);
    scan(a[0][0]);
    dp[0][0] = a[0][0];
    for (int j = 1; j<c; ++j) {
        scan(a[0][j]);
        dp[0][j] = dp[0][j-1]+a[0][j];
    }
    for (int i = 1; i<r; ++i) {
        scan(a[i][0]);
        dp[i][0] = dp[i-1][0]+a[i][0];
        for (int j = 1; j<c; ++j) {
            scan(a[i][j]);
        }
    }
    
    for (int i = 1; i<r; ++i) {
        for (int j = 1; j<c; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+a[i][j];
        }
    }
    
    cout<<dp[r-1][c-1]<<'\n';
    
    return 0;
}
