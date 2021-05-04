// https://dmoj.ca/problem/ccc07s5
// 05/2021

#if 1
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <climits>

using namespace std; typedef unsigned int uint; typedef long long ll; typedef unsigned long long ull; typedef long double dl; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> static void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> static void scan (vector<T>& v, int start, int end) { for (int i = start; i<end; ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; c[i] = '\0'; }
template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); } template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); } template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (vector<T>& v) { for (T el:v) print(el, ' '); putchar('\n'); }
template<class T> void print (vector<T>&& v) { print(v); }

// Adjust the vectors to global variables later
const int mxN = 3e4;
int n, b, w;
vec<int> pins(mxN);
vec<vec<int>> dp(2, vec<int>(mxN));

void solve() {

    int n, b, w; scan(n, b, w);
    vec<int> pins(n); scan(pins, 0, n);

    // Create a sum array for O(1) range sum
    // Obtain original value with dp[i]-dp[i-1]
    for (int i = 1; i<n; ++i) {
        pins[i] += pins[i-1];

        // dp[pin] = max score from 0 to pin with b balls
        dp[1][i] = dp[0][i] = 0;
    }

    dp[1][0] = dp[0][0] = 0;
    
    for (int balls = 1; balls<=b; ++balls) {

        for (int pin = 0; pin<n; ++pin) {

            if (pin<balls*w)
                dp[1][pin] = pins[pin];
            else
                dp[1][pin] = max(dp[1][pin-1], dp[0][pin-w]+pins[pin]-pins[pin-w]);

        }

        // Make current into previous
        copy(dp[1].begin()+balls*w-1, dp[1].begin()+n, dp[0].begin()+balls*w-1);

    }

    print(dp[0][n-1]);

}

/*
1
9 2 3
2 8 5 1 9 6 9 3 2

can start a new start everytime the last interval is a one
1
9 2 3
2 1 5  8  9  6  9  3  2

2 3 8 14 22 23 24 24 24
2 3 8 16 25 31 38 40 40

State will be the end range and the number of balls available
Any range of pins can be taken out with adjacent ball throws
Need to count the end point when there is not enough space
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; scan(t);
    while (t--) solve();
    return 0;
}
#endif
