// https://dmoj.ca/problem/vmss15c1p4
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
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

struct Edge {

    int destination, distance;
    Edge (int destination = 0, int distance = 0)
        : destination(destination), distance(distance) {}
    bool operator> (const Edge e) const {
        return distance>e.distance;
    }

};

void solve() {

    int maxKilometers, n, m, numFoodBasics;
    scan(maxKilometers); scan(n); scan(m); scan(numFoodBasics);
    vec<int> foodBasics(numFoodBasics);
    scan(all(foodBasics));

    vec<vec<Edge>> adj(n+1);
    for (int i = 0; i<m; ++i) {
        int current, destination, distance;
        scan(current); scan(destination); scan(distance);
        adj[current].emplace_back(destination, distance);
    }

    priq<Edge, vec<Edge>, greater<Edge>> pq;
    vec<int> dis(n+1, INT_MAX);
    dis[0] = 0;
    pq.emplace(0, dis[0]);

    while (pq.size()) {

        auto [u, uw] = pq.top(); pq.pop();
        if (uw>dis[u]) continue;

        for (const auto& [v, vw]:adj[u]) {
            if (dis[v]>dis[u]+vw) {
                dis[v] = dis[u]+vw;
                pq.emplace(v, dis[v]);
            }
        }

    }

    int cnt = 0;
    for (int& foodBasic:foodBasics) {
        if (dis[foodBasic]<=maxKilometers) ++cnt;
    }
    print(cnt);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
