// 08/2020
// https://www.hackerrank.com/challenges/find-digits/problem

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ans = 0, n;
    scanf("%d", &n);
    int m = n;
    while (m) {
        if (m%10)
            ans += n%(m%10)==0;
        m /= 10;
    }
    printf("%d\n", ans);
}

int main() {

    int t; scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
    
}
