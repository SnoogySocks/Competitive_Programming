// https://dmoj.ca/problem/dmopc20c4p1
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

/*
n(n+1)/2 = sum of first integers

5 11

y = -x+4
x = -1

1
5 7
3 5

y = -x+8
y = 5, x = 3

1
5 8
2 5
3 4

15-x-y=8
y = -x+7


5 5
1 9
2 8
3 7
4 6

1
5 9
1 5
*/

void solve() {

    ll n, s; scan(n); scan(s);
    ll sum, b, x, y;
    sum = n*(n+1ll)>>1ll;
    b = sum-s;
    
    // Impossible if b<3 or 2*n-1<b
    if (b<3||2*n-1<b) {
        print(0);
        return;
    }

    /*
        Starting point is at x,yE[1, n]
        y = -x+b
        y = -1+b
        or 
        x = b-n

        y = -1+7 = 6
        x = 7-5 = 2
    */
    x = 1;
    y = -1+b;
    if (y>n) {
        x = b-n;
        y = n;
    }
    b = y-x;
    print((b&1ll)?(b>>1ll)+1:b>>1ll);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 1
    int t; scan(t); while(t--) solve();
#else
    solve();
#endif
    return 0; 
}
