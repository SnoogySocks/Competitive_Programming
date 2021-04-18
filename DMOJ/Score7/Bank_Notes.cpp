// https://dmoj.ca/problem/banknotes
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
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; c[i] = '\0'; }
template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); } template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); } template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (vector<T>& v) { for (T el:v) print(el, ' '); putchar('\n'); }
template<class T> void print (vector<T>&& v) { print(v); }

const int mxN = 1e9;

struct Bank {
    int note, num;
    Bank (int note = 0, int num = 0) : note(note), num(num) {}
    bool operator> (const Bank& bank) const {
        return note>bank.note;
    }
};

void solve() {

    int n; scan(n);
    vec<Bank> bank(n);
    for (int i = 0; i<n; ++i) {
        scan(bank[i].note);
    }
    for (int i = 0; i<n; ++i) {
        scan(bank[i].num);
    }
    sort(all(bank), greater<Bank>());
    int target; scan(target);

    // dp[target][number of notes of this kind] = minimum number of notes
    vec<int> dp(target+1, mxN), cnt(target+1);
    dp[0] = 0;

    for (int i = 0; i<n; ++i) {
        // Reset dp cnt with 0
        fill(all(cnt), 0);
        auto [note, num] = bank[i];
        for (int t = note; t<=target; ++t) {
            if (t-note>=0&&cnt[t-note]!=num&&dp[t]>dp[t-note]+1) {
                dp[t] = dp[t-note]+1;
                cnt[t] = cnt[t-note]+1;
            }
        }
    }
    
    print(dp[target]);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
