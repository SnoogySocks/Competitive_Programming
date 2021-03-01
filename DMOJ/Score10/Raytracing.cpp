// https://dmoj.ca/problem/raytracing
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

vec<vec<int>> bit;

void updatej (int i, int j, int val) {
    for (++j; j<bit.size(); j += j&-j) {
        bit[i][j] += val;
    }
}

void updatei (int i, int j, int val) {
    for (++i; i<bit.size(); i += i&-i) {
        updatej(i, j, val);
    }
}

int queryj (int i, int j) {
    int sum = 0;
    for (++j; j>=1; j -= j&-j) {
        sum += bit[i][j];
    }
    return sum;
}

int queryi (int i, int j) {
    int sum = 0;
    for (++i; i>=1; i -= i&-i) {
        sum += queryj(i, j);
    }
    return sum;
}

void solve() {

    // Create a bit of bits, bit[i][j]
    // i = the position
    // j = # of trees with heights <= i
    int n; scan(n);
    vec<int> heights(n);
    bit = vec<vec<int>>(n+1, vec<int>(n+1));
    for (int i = 0; i<n; ++i) {
        scan(heights[i]);
        updatei(i, heights[i], 1);
    }

    // For each query, find how many in between the height up until position
    // Then do the same for the other range
    // Then subtract them
    int q; scan(q);
    vec<int> qs(5);
    while (q--) {
        scan(qs[0]);
        if (qs[0]==1) {
            scan(qs.begin()+1, qs.end());
            int left, right;
            left = queryi(qs[1]-1, qs[4])-queryi(qs[1]-1, qs[3]-1);
            right = queryi(qs[2], qs[4])-queryi(qs[2], qs[3]-1);
            print(max(right-left, 0));
        } else if (qs[0]==2) {
            scan(qs.begin()+1, qs.begin()+3);
            updatei(qs[1], heights[qs[1]], -1);
            updatei(qs[1], qs[2], 1);
            heights[qs[1]] = qs[2];
        }
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
