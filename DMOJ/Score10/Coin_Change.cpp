// https://dmoj.ca/problem/cchange
// 01/2021

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x,n; cin>>x>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    
    vector<int> dp(x+1);
    dp[0] = 0;
    
    for (int i = 1; i<=x; ++i) {
        dp[i] = INT_MAX-1;
        for (int j = 0; j<n; ++j) {
            if (i-v[j]>=0) {
                dp[i] = min(dp[i], dp[i-v[j]]+1);
            }
        }
    }
    
    cout<<dp[x]<<'\n';
    
    return 0;
    
}
