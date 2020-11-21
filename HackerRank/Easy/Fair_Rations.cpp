// 08/2020
// https://www.hackerrank.com/challenges/fair-rations/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;

int main() {

    int n, temp; scanf("%d", &n);
    bool b[mxN];
    for (int i = 0; i<n; i++) {
        scanf("%d", &temp);
        b[i] = temp&1;
    }

    int ans = 0;
    for (int i = 0; i<n-1; i++) {
        if (b[i]) {
            b[i+1] ^= 1;
            ans += 2;
        }
    }
    if (b[n-1]) puts("NO");
    else printf("%d\n", ans);

    return 0;
    
}
