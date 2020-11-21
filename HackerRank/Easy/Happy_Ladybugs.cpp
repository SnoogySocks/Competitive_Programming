// 08/2020
// https://www.hackerrank.com/challenges/happy-ladybugs/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;
const int mxN2 = 26;

void solve() {

    int n; scanf("%d", &n);
    getchar();
    int a[mxN2]{};
    int c1, c2, c3, j;
    bool has_ = false;
    bool m = true;
    c2 = c3 = 0;
    j = 0;
    for (int i = 0; i<n; i++) {
        c1 = getchar();
        if (c1=='_') {
            has_ = true;
            continue;
        }
        a[c1-'A']++;

        if (c3) m &= c1==c2||c2==c3;
        else if (c2) m &= c1==c2;
        c3 = c2;
        c2 = c1;
    }
    getchar();

    for (int i = 0; i<mxN2; i++) {
        if (a[i]==1) {
            puts("NO");
            return;
        }
    }
    puts(m&&!has_||has_?"YES":"NO");
    
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
    
}
