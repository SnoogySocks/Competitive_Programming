// 08/2020
// https://www.hackerrank.com/challenges/permutation-equation/problem

#include <bits/stdc++.h>

using namespace std;

const size_t mxN = 51;
int a[mxN];

int main() {

    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a[x] = i;
    }

    for (int x = 1; x <= n; x++) {
        printf("%d\n", a[a[x]]);
    }
    
    return 0;
    
}
