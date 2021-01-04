// https://dmoj.ca/problem/dwite09c1p3
// 01/2020

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int m, k, ans;
    for (int i = 0; i<5; ++i) {
        scanf("%d", &m);
        ans = 0;
        for (int j = 1; j<=m; ++j) {
            scanf("%d", &k);
            ans ^= j^k;
        }
        printf("%d\n", ans^(m+1));
    }
    
    return 0;
    
}
