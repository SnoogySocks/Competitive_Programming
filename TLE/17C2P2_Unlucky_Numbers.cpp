// https://dmoj.ca/problem/tle17c2p2
// 1/2021

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
#define f_list forward_list
#define u_set unordered_set
#define u_map unordered_map
#define pri_q priority_queue

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T&n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class C, class S> void scan (C& c, S size) { for (S i = 0; i<size; i++) scan(c[i]); }
void scan (char* c, int size, char&& escape = '\n') { if (c[0]) memset(c, 0, size); char buf; do buf = getchar(); while ((buf<'0'||'9'<buf)&&(buf<'A'||'Z'<buf)&&(buf<'a'||'z'<buf)); for (int i = 0; buf!=escape; buf = getchar())c[i++] = buf; if (c[size-1]) throw out_of_range("STRING SIZE TOO SMALL"); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) cout<<c[i]<<'\n'; }

const int mxN = 1e6;

void solve() {

    int k; scan(k);
    int diff[mxN+1]{};
    for (int i = 0; i<k; ++i) {
        int j; scan(j);
        diff[j] = 1;
    }
    for (int i = 1; i<=mxN; ++i) {
        diff[i] += diff[i-1];
    }
    int n; scan(n);
    while (n--) {
        int j; scan(j);
        print(j-diff[j]);
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
#if 0
    int t; scan(t); while(t--) solve();
#else
    solve();
#endif
    return 0; 
}
