// https://dmoj.ca/problem/vmss7wc16c2p2
// 12/2020

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+1;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string s; cin>>s;
    int dif[mxN] {};

    for (int i = 0; i<s.size(); ++i) {
        dif[i+1] = dif[i]+(s[i]=='G');
    }
    
    int q; cin>>q;
    int i,j;
    while (q--) {
        cin>>i>>j;
        cout<<dif[j+1]-dif[i]<<'\n';
    }
    
    return 0;
    
}
