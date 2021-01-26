// https://dmoj.ca/problem/acsl1p3
// 01/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 158;

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    
    int n; cin>>n;
    vector<int> fac; fac.reserve(mxN);
    fac.push_back(1);
    
    int prod, rem;
    rem = 0;
    for (int i = 2; i<=n; ++i) {
        for (int j = 0; j<fac.size(); ++j) {
            prod = i*fac[j]+rem;
            fac[j] = prod%10;
            rem = prod/10;
        }
        while (rem>0) {
            fac.push_back(rem%10);
            rem /= 10;
        }
    }
    int cnt = 0;
    for (int i: fac) {
        cnt += i==0;
    }
    cout<<cnt<<'\n';
    
}
