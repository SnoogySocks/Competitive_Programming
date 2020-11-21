// 08/2020
// https://www.hackerrank.com/challenges/pairs/problem

#include <bits/stdc++.h>

using namespace std;

const size_t mxN = 1e5;

int main() {

    size_t n, k; cin >> n >> k;
    unordered_set<size_t> s; s.reserve(mxN);
    size_t j;
    size_t ans = 0;
    for (size_t i = 0; i<n; i++) {
        cin >> j;
        s.insert(j);
        ans += (j>k&&s.count(j-k))+(j<INT_MAX-k&&s.count(j+k));
    }
    cout << ans << '\n';

    return 0;
    
}
