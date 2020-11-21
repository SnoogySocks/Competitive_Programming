// 08/2020
// https://www.hackerrank.com/challenges/two-pluses/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 17;
const int mxM = (mxN-1)/2;

char grid[mxN][mxN]{};
int dy[] { 1, 0, -1, 0 };
int dx[] { 0, 1, 0, -1 };

int psize (int y, int x) {
    int _y, _x;
    bool ok = true;
    int j;
    for (j = 1; ok; j++) for (int k = 0; k<4&&ok; k++) {
        _y = y+j*dy[k], _x = x+j*dx[k];
        if (grid[_y][_x]==0||grid[_y][_x]=='B') ok = false;
    }
    return j-2;
}

int main() {

    int r, c; scanf("%d%d", &r, &c);
    r++, c++;
    for (int i = 1; i<r; i++) {
        scanf("%s", grid[i]+1);
    }
    vector<pair<int, int>> areas[mxM];
    for (int y = 1; y<r; y++) for (int x = 1; x<c; x++) {
        if (grid[y][x]==0||grid[y][x]=='B') continue;
        areas[psize(y, x)].emplace_back(y, x);
    }
    int am, ac;
    am = 0;
    int y1, x1, y2, x2;
    int ydif, xdif;
    for (int s1 = mxM-1; s1>=1; s1--) for (int c1 = 0; c1<areas[s1].size(); c1++) {
        y1 = areas[s1][c1].first;
        x1 = areas[s1][c1].second;
        for (int s2 = s1; s2>=0; s2--) for (int c2 = 0; c2<areas[s2].size(); c2++) {
            y2 = areas[s2][c2].first;
            x2 = areas[s2][c2].second;
            ac = (s1*4+1)*(s2*4+1);
            if (am>=ac||y2==y1&&x1==x2) continue;
            ydif = abs(y2-y1);
            xdif = abs(x2-x1);
            for (int i = s1; i>=1; i--) for (int j = s2; j>=0; j--) {
                ac = (i*4+1)*(j*4+1);
                if (am<ac&&!(ydif<=i&&xdif<=j||ydif<=j&&xdif<=i)
                    &&!(x1==x2&&i+j>ydif-1||y1==y2&&i+j>xdif-1)) {
                    am = ac;
                }
            }
        }
    }
    
    printf("%d\n", (am==0&&areas[0].size()>1)?1:am);
}
