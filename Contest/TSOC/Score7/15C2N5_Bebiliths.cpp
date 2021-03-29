// https://dmoj.ca/problem/tsoc15c2p5
// 03/2021

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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

struct bebilith {
    int speed, venomDistance, clawSharpness, rank;
};

void solve() {

    int exConvictSpeed, n; scan(exConvictSpeed); scan(n);

    vec<bebilith> bebiliths(n);
    for (int i = 0; i<n; ++i) {
        scan(bebiliths[i].speed);
        scan(bebiliths[i].venomDistance);
        scan(bebiliths[i].clawSharpness);
        bebiliths[i].rank = i+1;
    }

    // Faster speed dangerous
    // Same speed, slower than ex-convicts, shoots venom furthest
    // Same speed, faster or at pace with ex-convicts, sharpest claws
    sort(all(bebiliths), [exConvictSpeed](bebilith b1, bebilith b2) {
        if (b1.speed==b2.speed) {
            if (b1.speed<exConvictSpeed) return b1.venomDistance>b2.venomDistance;
            return b1.clawSharpness>b2.clawSharpness;
        }
        return b1.speed>b2.speed;
        });

    int q; scan(q);
    while (q--) {
        int i; scan(i);
        print(bebiliths[i-1].rank);
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while (t--) solve();
#else
    solve();
#endif
    return 0;
}
#endif
