// https://dmoj.ca/problem/nccc2j3s1
// 01/2021

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    ios_base::sync_with_stdio(true);
    cin.tie(NULL), cout.tie(NULL);
    
    int n; cin>>n;
    ll max,sum,i;
    max = sum = 0;
    while (n--) {
        cin>>i;
        sum += i;
        if (max<i) max = i;
    }
    cout<<min(sum-max, sum/2)<<'\n';
    
    return 0;
    
}
