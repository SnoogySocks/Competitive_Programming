// 08/2020
// https://www.hackerrank.com/challenges/circular-array-rotation/problem

#include <bits/stdc++.h>

using namespace std;

const size_t mxN = 10e5;
int a[mxN];

int main() {

    ios_base::sync_with_stdio(true);
    cin.tie(NULL);

    int n, r, q;
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    r = r%n;
    int m;
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);
        // m -= r;
        // if (m<0) m += n;
        // printf("%d\n", a[m]);
        printf("%d\n", a[(m-r<0)?m-r+n:m-r]);
    }

    return 0;
    
}
// 1 2 3
