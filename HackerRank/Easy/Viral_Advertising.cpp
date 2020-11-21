// 08/2020
// https://www.hackerrank.com/challenges/strange-advertising/problem

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; scanf("%d", &n);
    int liked = 2, cumulative = 2;

    for (int i = 1; i < n; i++) {
        liked *= 1.5;
        cumulative += liked;
    }
    printf("%d", cumulative);
    
    return 0;

}

/*
Day Shared Liked Cumulative
1      5     2       2
2      6     3       5
3      9     4       9
4     12     6      15
5     18     9      24
6     27    13      37
*/
