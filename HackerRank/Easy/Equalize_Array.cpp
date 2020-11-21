// 08/2020
// https://www.hackerrank.com/challenges/equality-in-a-array/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 101;

#define amax(a, b) if (a<b) a = b

int main() {

    int n, a[mxN]{}; scanf("%d", &n);
    int el, max_el = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &el);
        a[el]++;
        amax(max_el, a[el]);
    }
    printf("%d", n-max_el);
    
    return 0;

}
