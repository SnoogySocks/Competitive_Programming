// https://dmoj.ca/problem/vmss7wc16c3p3
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
#include <list>
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
template<class T> static void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; } template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); } template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); } template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!'||'~'<buf); int i; for (i = 0; buf!='\n'&&buf!=escape; buf = getchar()) c[i++] = buf; c[i] = '\0'; }
template<class T> static void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (vector<T>& v) { for (T el:v) print(el, ' '); putchar('\n'); }
template<class T> void print (vector<T>&& v) { print(v); }

struct Road {
    int house, drivingTime;
    Road (int house, int drivingTime) : house(house), drivingTime(drivingTime) {}
    bool operator> (const Road& r) const {
        return drivingTime>r.drivingTime;
    }
};

void solve() {

    const int unvisited = INT_MAX;

    int numHouses, numRoads, destination, queries;
    scan(numHouses, numRoads, destination, queries);
    vec<vec<Road>> houses(numHouses+1);
    for (int i = 0; i<numRoads; ++i) {
        int houseA, houseB, drivingTime;
        scan(houseA, houseB, drivingTime);
        houses[houseA].emplace_back(houseB, drivingTime);
        houses[houseB].emplace_back(houseA, drivingTime);
    }

    vec<int> dis(numHouses+1, unvisited);
    queue<Road, list<Road>> q;
    dis[destination] = 0;
    q.emplace(destination, dis[destination]);

    while (q.size()) {

        auto [cHouse, cDrivingTime] = q.front(); q.pop();
        
        for (auto& [vHouse, vDrivingTime]:houses[cHouse]) {
            if (dis[vHouse]>dis[cHouse]+vDrivingTime) {
                dis[vHouse] = dis[cHouse]+vDrivingTime;
                q.emplace(vHouse, dis[vHouse]);
            }
        }

    }

    while (queries--) {
        int start; scan(start);
        print(dis[start]!=unvisited?dis[start]:-1);
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
#endif
