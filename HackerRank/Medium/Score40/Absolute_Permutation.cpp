// 08/2020
// https://www.hackerrank.com/challenges/absolute-permutation/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

void solve() {

    int n, k; scanf("%d%d", &n, &k);
    if (k==0) for (int i = 1; i<=n; i++) printf("%d ", i);
    else if (n%k||(n/k)&1) printf("-1"); 
    else {
        int d;
        for (int i = 0; i<n; i++) {
            d = i/k;
            printf("%d ", 1+(d&1?i-k:i+k));
        }
    }
    
}
int main() {

    int t; scanf("%d", &t);
    while (t--) {
        solve();
        putchar('\n');
    }

    return 0;
    
}
