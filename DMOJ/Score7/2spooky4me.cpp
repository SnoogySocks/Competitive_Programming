// https://dmoj.ca/problem/2spooky4me
// 1/2021

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
typedef long long ll;
#define u_set unordered_set
#define u_map unordered_map
#define pri_q priority_queue

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class C, class S> void scan (C& c, S size) { for (S i = 0; i<size; i++) scan(c[i]); }
void scan (char* c, int size, char&& escape = '\n') { if (c[0]) memset(c, 0, size); char buf; do buf = getchar(); while ((buf<'0'||'9'<buf)&&(buf<'A'||'Z'<buf)&&(buf<'a'||'z'<buf)); for (int i = 0; buf!=escape; buf = getchar())c[i++] = buf; if (c[size-1]) throw out_of_range("STRING SIZE TOO SMALL"); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class C, class S> void print (C c, S size) { for (int i = 0; i<size; i++) cout<<c[i]<<'\n'; }

void solve() {

    int n,l,s;
    scan(n); scan(l); scan(s);
    
    vector<pair<int, int>> v; v.reserve(n*2);
    while (n--) {
        int a,b,s;
        scan(a); scan(b); scan(s);
        v.emplace_back(a, s); v.emplace_back(b+1, -s);
    }
    v.emplace_back(1, 0); v.emplace_back(l+1, 0);
    sort(v.begin(), v.end());
    int sum, ans, prev;
    sum = ans = 0;
    prev = 1;
    for (int i = 0; i<v.size(); ++i) {
        if (sum<s) ans += v[i].first-prev;
        sum += v[i].second;
        prev = v[i].first;
    }
    print(ans);

}

int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL); 
#if 0
    int t; scan(t); while(t--) solve();
#else
    solve();
#endif
    return 0; 
}
