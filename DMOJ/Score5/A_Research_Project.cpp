// https://dmoj.ca/problem/acmtryouts3a
// 1/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; scanf("%d", &t);
    int n, min, max, i;
    while (t--) {
        scanf("%d", &n);
        min = mxN, max = 1;
        while (n--) {
            scanf("%d", &i);
            if (min>i) min = i;
            if (max<i) max = i;
        }
        printf("%d %d\n", min, max);
    }
    
    return 0;
    
}
