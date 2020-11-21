// 08/2020
// https://www.hackerrank.com/challenges/sherlock-and-squares/problem

#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b; scanf("%d", &a);
    while (~scanf("%d%d", &a, &b)) {
        printf("%d\n", (int)sqrt(b)-(int)sqrt(a-1));
    }
    
    return 0;
    
}
