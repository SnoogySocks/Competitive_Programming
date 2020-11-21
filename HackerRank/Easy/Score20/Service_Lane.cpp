// 08/2020
// https://www.hackerrank.com/challenges/service-lane/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int main() {

    int n, t; scanf("%d%d", &n, &t);
    int w[mxN];
    for (int i = 0; i<n; i++) {
        scanf("%d", &w[i]);
    }
    int i, j, ans;
    for (int p = 0; p<t; p++) {
        scanf("%d%d", &i, &j);
        ans = 3;
        while (i<=j&&ans!=1) {
            if (w[i]<ans) {
                ans = w[i];
            }
            i++;
        }
        printf("%d\n", ans);
    }

    return 0;
    
}
