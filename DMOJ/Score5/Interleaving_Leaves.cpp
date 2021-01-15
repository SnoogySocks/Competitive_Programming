// https://dmoj.ca/problem/acmtryouts0b
// 1/2021

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s[2];
    cin>>n>>s[0]>>s[1];
    for (int i = 2*n-1; i>=0; --i) {
        putchar(s[i%2][i/2]);
    }
    putchar('\n');
}

int main() {
    int t; cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
