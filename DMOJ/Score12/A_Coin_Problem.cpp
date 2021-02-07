// https://dmoj.ca/problem/acoinproblem
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
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while ((buf<'0'||'9'<buf)&&(buf<'A'||'Z'<buf)&&(buf<'a'||'z'<buf)); for (int i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); c.push_back('\0'); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

const int mxC = 1e4;

void solve() {

    int n, m; scan(n); scan(m);
    vector<int> coins(n);
    scan(all(coins));
    vector<int> qs(m);
    vector<pii> qsmp; qsmp.reserve(m+1);
    int a, b;
    int max = 0;
    for (int i = 0; i<m; ++i) {
        scan(a); scan(b);
        amax(max, a);
        qs[i] = a;
        qsmp.emplace_back(b, i);
    }
    sort(all(qsmp));
    qsmp.emplace_back(0, 0);
    
    vector<int> dp(max+1, mxC+1);
    dp[0] = 0;
    int cur = 0;
    for (int i = 0; i<n; ++i) {
        for (int j = coins[i]; j<=max; ++j) {
            amin(dp[j], dp[j-coins[i]]+1);
        }
        while (qsmp[cur].first==i+1) {
            qs[qsmp[cur].second] = dp[qs[qsmp[cur].second]]!=mxC+1?dp[qs[qsmp[cur].second]]:-1;
            ++cur;
        }
    }
    for (int i:qs) {
        print(i);
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
