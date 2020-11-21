// 08/2020
// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem

#include <bits/stdc++.h>

using namespace std;
const size_t mxN = 25;
bool c[mxN];

int main() {

    int ans = 100;
    int n, k;
    scanf("%d%d", &n, &k);

    int input;
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        c[i] = input;
    }
    ans -= 2*c[0]+1;
    int i = k;
    while (i%n != 0) {
        ans -= 2*c[i%n]+1;
        
        i += k;
    }

    printf("%d", ans);

    return 0;
    
}
