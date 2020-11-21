// 08/2020
// https://www.hackerrank.com/challenges/cut-the-sticks/problem

#include <bits/stdc++.h>

using namespace std;
const size_t mxN = 1001;
int sticks[mxN]{};

#define amax(a, b) if (a<b) a = b
#define amin(a, b) if (a>b) a = b

int main() {

    int n; scanf("%d", &n);

    int max_l = 0;
    int min_l = n;
    for (int i = 0; i < n; i++) {
        int stick; scanf("%d", &stick);
        sticks[stick]++;
        amax(max_l, stick);
        amin(min_l, stick);
    }

    while (min_l<=max_l) {
        if (sticks[min_l]) {
            printf("%d\n", n);
            n -= sticks[min_l];
        }
        min_l++;
    }

    return 0;
    
}
