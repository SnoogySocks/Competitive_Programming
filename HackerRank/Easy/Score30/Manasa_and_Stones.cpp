// 08/2020
// https://www.hackerrank.com/challenges/manasa-and-stones/problem

#include <bits/stdc++.h>

using namespace std;

int a, b;

void solve() {

    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    if (a>b) {
        swap(a, b);
    } else if (a==b) {
        printf("%d", a*(n-1));
        return;
    }
    int sum = a*(n-1);
    for (int i = 0; i<n; i++) {
        printf("%d ", sum);
        sum += b-a;
    }

}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        solve();
        putchar('\n');
    }
    
}

