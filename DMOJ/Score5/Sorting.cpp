// https://dmoj.ca/problem/a4b1
// 1/2021

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    int a[100];
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
    }
    sort(a, a+n);
    for (int i = 0; i<n; ++i) {
        cout<<a[i]<<'\n';
    }
    return 0;
}
