// 08/2020
// https://www.hackerrank.com/challenges/cavity-map/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

int main() {

    int n; scanf("%d", &n);
    int grid[mxN][mxN];
    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            scanf("%1d", &grid[y][x]);
        }
    }

    for (int x = 0; x<n; x++) {
        putchar(grid[0][x]+'0');
    }
    putchar('\n');
    for (int y = 1; y<n-1; y++) {
        putchar(grid[y][0]+'0');
        for (int x = 1; x<n-1; x++) {
            if (grid[y][x]>grid[y-1][x]&&grid[y][x]>grid[y+1][x]&&grid[y][x]>grid[y][x-1]&&grid[y][x]>grid[y][x+1]) {
                putchar('X');
            } else {
                putchar(grid[y][x]+'0');
            }
        }
        putchar(grid[y][n-1]+'0');
        putchar('\n');
    }
    if (n>1) 
        for (int x = 0; x<n; x++) {
            putchar(grid[n-1][x]+'0');
        }

    return 0;
    
}
