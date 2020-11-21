// 08/2020
// https://www.hackerrank.com/challenges/beautiful-triplets/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e4+1;

int main() {

    int n, d;
    scanf("%d%d", &n, &d);
    if (n<3) {
        putchar('0');
        return 0;
    }

    int a[mxN]{};
    int maxn = -1, temp;
    for (int i = 0; i<n; i++) {
        scanf("%d", &temp);
        a[temp]++;
        if (maxn<temp) maxn = temp;
    }
    int ans = 0;
    for (int i = 0; i<=maxn-2*d; i++) {
        if (a[i]&&a[i+d]&&a[i+2*d]) {
            ans += a[i]*a[i+d]*a[i+2*d];
        }
    }

    printf("%d", ans);

    return 0;
    
}
/*
3 20
23960 23980 24000
*/
