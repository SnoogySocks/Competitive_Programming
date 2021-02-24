// https://dmoj.ca/problem/dmopc14c2p6
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

vec<int> bit;

void update (int i, int val) {
    for (++i; i<bit.size(); i += i&-i) {
        bit[i] += val;
    }
}

int query (int i) {
    int sum = 0;
    for (++i; i>0; i -= i&-i) {
        sum += bit[i];
    }
    return sum;
}

void solve() {

    int n; scan(n);
    vec<pii> trees(n+1);
    for (int i = 0; i<n; ++i) {
        scan(trees[i].first);
        trees[i].second = i;
    }
    sort(all(trees), greater());

    int q; scan(q);
    vec<vec<int>> queries(q+1, vec<int>(4));
    for (int i = 0; i<q; ++i) {
        scan(queries[i].begin(), queries[i].end()-1);
        queries[i][3] = i;
    }
    sort(all(queries), [](vec<int>& a, vec<int>& b) { return a[2]>b[2]; });

    bit = vec<int>(n+1);
    vec<int> output(q);

    for (int qi = 0, ti = 0; qi<q; ++qi) {
        for (; trees[ti].first>=queries[qi][2]; ++ti)
            update(trees[ti].second, trees[ti].first);
        output[queries[qi][3]] = query(queries[qi][1])-query(queries[qi][0]-1);
    }

    for (int i = 0; i<q; ++i) {
        print(output[i]);
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
