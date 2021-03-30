// https://dmoj.ca/problem/ccc13s2
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
#include <bitset>

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
void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while ((buf<'0'||'9'<buf)&&(buf<'A'||'Z'<buf)&&(buf<'a'||'z'<buf)); for (;  buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); c.push_back('\0'); }
template<class T> void print (T n, const char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

void solve() {

    int w, n; scan(w); scan(n);
    int sum = 0;
    deque<int> cars;
    for (int i = 0; i<n; ++i) {
        if (i>=4) {
            sum -= cars.front();
            cars.pop_front();
        }
        int car; scan(car);
        cars.push_back(car);
        sum += car;
        if (sum>w) {
            print(i);
            return;
        }
    }
    print(n);
    
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
