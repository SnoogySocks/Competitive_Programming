// 08/2020
// https://www.hackerrank.com/challenges/save-the-prisoner/problem

#include <bits/stdc++.h>

using namespace std;

/*
5 n 1
1: 1
2: 2
3: 3
4: 4
5: 0
6: 1
*/

void solve() {
    int p, c, s;
    scanf("%d%d%d", &p, &c, &s);
    int total = (c+s-2)%p;
    printf("%d\n", total+1);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}
