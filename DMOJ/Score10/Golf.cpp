// https://dmoj.ca/problem/ccc00s4
// 01/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 5280;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int d,n; cin>>d>>n;
    vector<int> c(n);
    for (int i = 0; i<n; ++i) {
        cin>>c[i];
    }
    
    vector<int> dp(d);
    dp[0] = 0;
    for (int i = 1; i<=d; ++i) {
        dp[i] = mxN+1;
        for (int j = 0; j<n; ++j) {
            if (i-c[j]>=0) 
                dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    if (dp[d]==mxN+1) {
        cout<<"Roberta acknowledges defeat."<<'\n';
    } else {
        cout<<"Roberta wins in "<<dp[d]<<" strokes."<<'\n';
    }
    
    return 0;
    
}
