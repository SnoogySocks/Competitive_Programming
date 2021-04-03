// https://dmoj.ca/problem/si17c1p8
// 01/2021#include <iostream>

#include <cstring>
#include <algorithm>

using namespace std;

const int mxC = 15+1;
const int mxV = 1e6+1;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; cin>>n>>t;
    int coins[mxC] {};
    for (int i = 1; i<=n; ++i) {
        cin>>coins[i];
    }

    /*
    dp[0][v] = number of ways to make v with the first c-1 coins
    dp[1][v] = number of ways to make v by adding the cth coin last
    */
    int dp[2][mxV] {};
    dp[0][0] = 1;

    // Calculate the number of ways to make v with the first c coins
    for (int c = 1; c<=n; ++c) {
        for (int v = 1; v<=t; ++v) {
            if (v-coins[c]>=0) {
                dp[1][v] = dp[0][v]+dp[0][v-coins[c]];
            }
        }
        for (int i = 0; i<=t; ++i) {
            dp[0][i] = (dp[1][i])? dp[1][i]:dp[0][i];
        }
    }

    cout<<dp[0][t]<<'\n';

    return 0;
}
