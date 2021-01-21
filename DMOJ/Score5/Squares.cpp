// https://dmoj.ca/problem/dmopc19c2p2
// 11/2020

#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cassert>
#include<assert.h>
#include<cmath>
#include<random>
#include<vector>
#include<bitset>
#include<set>
#include<memory>
#include<numeric>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<stack>
#include<sstream>
#include<math.h>
#include <ctype.h>

typedef long long ll;

template <typename T> void sc(T &number) { bool negative = false; register int c; number = 0;  c = getchar(); if (c=='-') { negative = true;  c = getchar(); } for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48; if (negative) number *= -1; }

#define fi(x, y) for(int i = x; i < y; i++)
#define fj(x, y) for(int j = x; j < y; j++)
#define mp make_pair
#define MOD 1000000007
#define endl "\n"
#define print2dArr(a,r,c) cout << #a << ":\n"; for(int i = 0; i < r; i++) { for(int j = 0; j < c; j++) { cout << a[i][j] << " "; } cout << endl;}
#define pi 2 * asin(1.0)
#define elif else if
#define pii pair<int, int>
#define pq priority_queue
// #define sc(n) scanf("%d", &n);

using namespace std;

struct point
{
    int x, y;
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////
int dp[500][500];
int main() {
    int n, m;
    sc(n);sc(m);
    int arr[n][m];
    fi(0, n) {
        fj(0, m) {
            sc(arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];
    fi(0, n) {
        fj(0, m) {
            if (i == 0 && j == 0) {
                continue;
            } elif (i == 0) {
                dp[i][j] = arr[i][j] + dp[i][j - 1];
            } elif (j == 0) {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
            }
        }
    }
    printf("%d", dp[n - 1][m - 1]);
    return 0;
}
