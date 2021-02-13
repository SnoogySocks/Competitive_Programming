//  https://dmoj.ca/problem/utso21p2
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
#include <cmath>

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

int gcd (int a, int b) {
    int temp;
    while (b) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

/*
23232 - 10
[2,3],[3,2],[2,3],[3,2],[2,3,2],[3,2,3],[2,3,2],[2,3,2,3],[3,2,3,2],[2,3,2,3,2]
2323 - 6
[2,3],[3,2],[2,3],[2,3,2],[3,2,3],[2,3,2,3]
232 - 3
[2,3],[3,2],[2,3,2]
23 - 1
[2,3]
2 - 0
[]

S = n(n-1)/2
2S = n^2-n
n = (1+sqrt(1+8S))/2

*/

void solve() {

    int s; scan(s);
    int n = (1+sqrt(1+8*s))/2; // size of array
    int num_sub = n*(n-1)/2; // number of prime subarrays
    int num1s = s-num_sub; // the number of 1s to add

    print(n);
    for (int i = 0; i<num1s; ++i) {
        print(1, ' ');
    }
    for (int i = 0; i<n-num1s; ++i) {
        print((i%2)?3:2, ' ');
    }
    
    putchar('\n');

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
