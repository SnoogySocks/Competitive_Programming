// 08/2020
// https://www.hackerrank.com/challenges/utopian-tree/problem

#include <bits/stdc++.h>

using namespace std;

// 2(2(2*1+1)+1)+1
// 4(2+1)+2+1
// 8+4+2+1

// 0: 1

// 1: 2*1

// 2: 2*1+1

// 3: 2(2*1+1)
//    4+2

// 4: 2(2*1+1)+1
//    4+2+1

void solve() {

    int n; scanf("%d", &n);
    // int ans = pow(2, (n/2+1)+(n&1))-((n&1)? 2 : 1);
    int ans = (1<<(n/2+1)+(n&1))-((n&1)? 2:1);
    printf("%d\n", ans);

}

int main() {
    
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}

/*
Period  Height
0          1
1          2
2          3
3          6
4          7
5          14
6          15
*/
