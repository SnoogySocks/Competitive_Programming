// https://dmoj.ca/problem/ccc21s3
// 03/2021

#if 1
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
#include <cmath>
#include <climits>

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

const ll mxN = 2e9+1001ll;

struct person {
    int w;
    ll p, d;
    bool isLeft;
    person (int w, ll p, ll d, bool isLeft) : w(w), p(p), d(d), isLeft(isLeft) {}
    bool operator< (person per) {
        return p<per.p||p==per.p&&w<per.w;
    }
    bool operator== (person per) {
        return p==per.p&&isLeft==per.isLeft;
    }
};

void solve() {

    int n; scan(n);
    /*
        From the first position 0 to p-d will give back positions of person i
        0 = seriesSum(0, p-d+1)
        p-d = 0

        From p+d to the last position maxEl will give forward positions of person i
        p+d = 0
        maxEl = seriesSum(0, maxEl-p-d+1)

        Each will be put in separately into the array

        sort the array
        
        Iterate through the array
        Let totalSpeed = current total people's running speed
        let tTotalTime = current total people's totalTime
        Add to tTotalTime the totalSpeed to get everyone's walking time

        2
        1 1 2
        3 1 1
    */

    vec<person> friends; friends.reserve(4*n+1);
    for (int i = 0; i<n; ++i) {
        int w;
        ll p, d; scan(p); scan(w); scan(d);
        // From [0, p-d]. pos at 0 will be time taken to get to 0
        friends.emplace_back(-w, 0ll, max(0ll, (p-d)*w), true);
        friends.emplace_back(w, max(0ll, p-d), 0ll, true);
        // From [p+d, mxN], pos at mxN will be time taken to get to mxN
        friends.emplace_back(w, p+d, 0ll, false);
        friends.emplace_back(-w, mxN, (mxN-p-d)*w, false);
    }
    sort(all(friends));
    friends.emplace_back(0ll, 0ll, 0ll, true);

    ll totalSpeed, tTotalTime, minimum;
    totalSpeed = tTotalTime = 0;
    minimum = LLONG_MAX;

    for (int i = 0; i<friends.size()-1;) {
        
        do {
            totalSpeed += friends[i].w;
            tTotalTime += friends[i].d;
            ++i;
        } while (friends[i]==friends[i-1]);
        
        // Get the range sum
        tTotalTime += totalSpeed*(friends[i].p-friends[i-1].p);
        amin(minimum, tTotalTime);

    }
    print(minimum);

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
