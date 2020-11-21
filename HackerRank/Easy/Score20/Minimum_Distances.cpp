// 08/2020
// https://www.hackerrank.com/challenges/minimum-distances/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+1;

int main() {

    unordered_map<int, int> mp;
    int n; scanf("%d", &n);
    int ans, temp;
    ans = mxN;
    for (int i = 0; i<n; i++) {
        scanf("%d", &temp);
        if (mp.count(temp)&&i-mp[temp]<ans) {
            ans = i-mp[temp];
        }
        mp[temp] = i;
    }

    printf("%d", (ans!=mxN)?ans:-1);

    return 0;
    
}
