// 08/2020
// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#include <bits/stdc++.h>

using namespace std;

int reverse (int num) {
    int reversed_n = 0;
    while (num) {
        reversed_n = (reversed_n<<3)+(reversed_n<<1)+num%10;
        num /= 10;
    }
    return reversed_n;
}

int main() {
    
    int i, j, k, ans;
    scanf("%d%d%d", &i, &j, &k);
    ans = 0;
    while (i <= j) {
        if (abs(i - reverse(i++))%k==0) {
            ans++;
        }
    }

    printf("%d", ans);
    
    return 0;
    
}
