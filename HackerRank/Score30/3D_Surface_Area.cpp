// 08/2020
// https://www.hackerrank.com/challenges/3d-surface-area/problem

#include <bits/stdc++.h>

using namespace std;
const int mxN = 102;

int main() {

    int h, w; scanf("%d%d", &h, &w);
    int a[mxN][mxN]{};
    
    for (int i = 1; i<h+1; i++) {
        for (int j = 1; j<w+1; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    
    int area = 2*(h*w+h+w);
    for (int i = 0; i<h+1; i++) {
        for (int j = 0; j<w+1; j++) {
            area += abs(a[i][j]-a[i][j+1])+abs(a[i][j]-a[i+1][j]);
        }
    }
    printf("%d", area);

    return 0;
    
}
