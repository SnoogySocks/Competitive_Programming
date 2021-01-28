// https://dmoj.ca/problem/mwc15c2p2
// 01/2021

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int mxN = 1e6+1;

int main () {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin>>n;
    vector<pii> tws(n+1);
    int top = 0;
    tws[0] = make_pair(0, mxN);
    
    for (int i = 0; i<n; ++i) {
        int t; cin>>t;
        while (top!=-1&&t>=tws[top].second) --top;
        cout<<i-tws[top].first<<' ';
        tws[++top] = make_pair(i, t);
    }
    cout<<'\n';
    
    return 0;
    
}
