// 08/2020
// https://www.hackerrank.com/challenges/flatland-space-stations/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int main() {

    int n, m; scanf("%d%d", &n, &m);
    int d[mxN];
    for (int i = 0; i<m; i++) {
        scanf("%d", &d[i]);
    }
    sort(d, d+m);
    int dif = max(d[0], n-1-d[m-1]);
    for (int i = 0; i<m; i++) {
        dif = max(dif, (d[i+1]-d[i])>>1);
    }
    printf("%d", dif);

    return 0;
    
}
