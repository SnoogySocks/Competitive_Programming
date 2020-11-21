// 08/2020
// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 300;

int m, n, a[mxN][mxN];

pair<int, int> at (int k, int i) {

    if (i+2*k<m) return make_pair(k+i, k);
    else if (i+4*k<m-1+n) return make_pair(m-k-1, i-m+3*k+1);
    else if (i+6*k<2*(m-1)+n) return make_pair(2*m+n-i-5*k-3, n-k-1);
    // m-k-1-(i-(m-2*k-1)-(n-2*k-1))
    return make_pair(k, 2*(m+n)-i-7*k-4);
    // n-k-1-(i-2*(m-2*k-1)-(n-2*k-1))

}
void rotate (int k, int len) {

    pair<int, int> coor;
    int prev = a[k][k];
    
    for (int i = 1; i<=len; i++) {
        coor = at(k, i);
        swap(prev, a[coor.first][coor.second]);
    }
    
}

int main() {

    int r; scanf("%d%d%d", &m, &n, &r);

    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int len, nr;
    for (int k = 0; k<min(m, n)/2; k++) {
        len = 2*(m+n-4*k)-4;
        nr = r%len;
        for (int i = 0; i<nr; i++) {
            rotate(k, len);
        }
    }

    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }

    return 0;
    
}
