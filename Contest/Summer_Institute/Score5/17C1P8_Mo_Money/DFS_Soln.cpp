// https://dmoj.ca/problem/si17c1p8
// 12/2020

#include <iostream>

using namespace std;

const int mxN = 1e6;
int a[15] {};
int n, t, ans;

void dfs (int cc, int cs) { // current coin, current sum
    cs += a[cc];
    if (cc>n||cs>=t) {
        if (cs==t) ++ans;
        return;
    }
    for (int i = cc+1; i<n; ++i) {
        dfs(i, cs);
    }
}

int main() {
    cin>>n>>t;
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i<n; ++i) {
        dfs(i, 0);
    }

    cout<<ans<<'\n';

    return 0;
}
