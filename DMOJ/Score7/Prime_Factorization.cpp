// https://dmoj.ca/problem/primefactor
// 01/2021

#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int n; cin>>n;
    int sqr = sqrt(n);
    while (n%2!=1) {
        printf("2 ");
        n /= 2;
    }
    for (int i = 3; i<=sqr&&n!=1;) {
        if (n%i==0) {
            printf("%d ", i);
            n /= i;
        }
        else i += 2;
    }
    if (n>2) printf("%d ", n);
    putchar('\n');
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    
    int t; cin>>t;
    
    while (t--) solve();
    
}
