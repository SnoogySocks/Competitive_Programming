// 08/2020
// https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>

using namespace std;
const int mxN = 1e5+1;

int main() {

    int n, k;
    scanf("%d%d", &n, &k);
    int rq, cq;
    scanf("%d%d", &rq, &cq);
    int b1 = rq-cq, b2 = rq+cq;
    int td = 2*n-2+min(n-rq, n-cq)+min(n-rq, cq-1)+min(rq-1, cq-1)+min(rq-1, n-cq);
    int d[4][2] {};
    int r, c, r2, c2;
    for (int i = 0; i<k; i++) {
        scanf("%d%d", &r, &c);
        r2 = n-r+1, c2 = n-c+1;
        if (rq==r) {
            if (cq<c&&d[0][0]<c2) {
                d[0][0] = c2;
            } else if (cq>c&&d[0][1]<c) {
                d[0][1] = c;
            }
        } else if (cq==c) {
            if (rq<r&&d[1][0]<r2) {
                d[1][0] = r2;
            } else if (rq>r&&d[1][1]<r) {
                d[1][1] = r;
            }
        } else if (b1==r-c) {
            if (rq<r&&d[2][0]<min(r2, c2)) {
                d[2][0] = min(r2, c2);
            } else if (rq>r&&d[2][1]<min(r, c)) {
                d[2][1] = min(r, c);
            }
        } else if (b2==r+c) {
            if (rq<r&&d[3][0]<min(r2, c)) {
                d[3][0] = min(r2, c);
            } else if (rq>r&&d[3][1]<min(r, c2)) {
                d[3][1] = min(r, c2);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            td-=d[i][j];
        }
    }
    printf("%d", td);

    return 0;
    
}
