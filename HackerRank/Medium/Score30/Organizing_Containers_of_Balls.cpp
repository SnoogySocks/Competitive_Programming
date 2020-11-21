// 08/2020
// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

void solve() {

    int n; scanf("%d", &n);
    int sc[mxN]{}, el;
    int st[mxN]{};

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d", &el);
            sc[i] += el;
            st[j] += el;
        }
    }
    sort(sc, sc+n);
    sort(st, st+n);

    for (int i = 0; i<n; i++) {
        if (sc[i]<st[i]) {
            puts("Impossible");
            return;
        }
    }
    puts("Possible");
    
}

int main() {
    
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
    
}
