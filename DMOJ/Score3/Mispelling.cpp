// https://dmoj.ca/problem/a1
// 12/2020

#include <bits/stdc++.h>

using namespace std;

char* c = new char[81]{};
void solve() {
    int n;
    scanf("%d %[^\n]s", &n, c);
    c[n-1] = '\0';
    printf(c);
    puts(c+n);
}
int main() {
    int t; cin>>t;
    for (int i = 1; i<=t; ++i) {
        cout<<i<<' ';
        solve();
    }
    
    return 0;
}
