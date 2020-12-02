// 12/2020
// https://www.hackerrank.com/challenges/insertion-sort/problem

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxN = 1e7;
const int mxM = 1e5;

int BIT[mxN+1];

// Calculate the number of preceding numbers
int getSum (int index) {
    int sum = 0;
    while (index) {
        sum += BIT[index];
        index -= index&-index;
    }
    return sum;
}

// Update BIT
void update (int index) {
    while (index<=mxN) {
        ++BIT[index];
        index += index&-index;
    }
}

// Find preceding numbers less than current
void solve () {

    int n, arr[mxM] {};
    memset(BIT, 0, 4*(mxN+1));
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    ll ans = 0;
    for (int i = n-1; i>=0; --i) {
        ans += getSum(arr[i]-1);
        update(arr[i]);
    }
    cout<<ans<<'\n';

}

int main() {

    int t; cin>>t;
    while (t--) {
        solve();
    }

}
