// 08/2020
// https://www.hackerrank.com/challenges/picking-numbers/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 101;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; scanf("%d", &n);
    int a[mxN]{};

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[num]++;
    }

    int max = 1;
    for (int i = 1; i < n; i++) {
        int sum = a[i]+a[i-1];
        if (max < sum) {
            max = sum;
        }
    }

    printf("%d", max);
    
    return 0;
    
}
