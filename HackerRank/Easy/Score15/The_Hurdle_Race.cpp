// 08/2020
// https://www.hackerrank.com/challenges/the-hurdle-race/problem

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int max = 0;

    int input;
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        if (max < input) {
            max = input;
        }
    }
    
    printf("%d", (max > k) ? max - k : 0);

    return 0;
    
}
