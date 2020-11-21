// 08/2020
// https://www.hackerrank.com/challenges/larrys-array/problem

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1000;

void solve() {

    int n; scanf("%d", &n);
    int a[mxN];
    for (int i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            ans ^= a[i]>a[j];
        }
    }
    puts(!ans?"YES":"NO");
    
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
    
}
