// 08/2020
// https://www.hackerrank.com/challenges/lisa-workbook/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

int main() {

    int n, k; scanf("%d%d", &n, &k);
    int ans, p, r;
    int prev = 0, cur;
    ans = 0;
    for (int i = 0; i<n; i++) {
        scanf("%d", &p);
        r = p%k;
        cur = prev+p/k+(r!=0);
        for (int j = 0; ++prev<=cur; j+=k) {
            if (j<prev&&prev<=j+((prev==cur&&r!=0)?r:k)) {
                ans++;
            }
        }
        prev = cur;
    }
    printf("%d", ans);
    
}
