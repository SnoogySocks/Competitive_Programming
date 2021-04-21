// https://dmoj.ca/problem/ccc07j5
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
template<class T> static void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; } template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); } template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); } template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; c[i] = '\0'; }
template<class T> static void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (vector<T>& v) { for (T el:v) print(el, ' '); putchar('\n'); }
template<class T> void print (vector<T>&& v) { print(v); }

void solve() {

    int minimum, maximum, n; scan(minimum, maximum, n);
    vec<int> motels { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
    motels.reserve(motels.size()+n);
    for (int i = 0; i<n; ++i) {
        int motel; scan(motel);
        motels.emplace_back(motel);
    }
    sort(all(motels));

    vector<ll> dp(motels.size());
    dp[0] = 1;

    for (int cur = 0; cur<motels.size(); ++cur) {
        for (int next = cur+1; next<motels.size(); ++next) {
            int dis = motels[next]-motels[cur];
            if (minimum<=dis&&dis<=maximum)
                dp[next] += dp[cur];
            else if (dis>maximum) break;
        }
    }
    print(dp.back());

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
