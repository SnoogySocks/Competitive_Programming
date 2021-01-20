// https://dmoj.ca/user
// 1/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 26;

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    
    int n,l;
    string s;
    cin>>n>>l;
    getline(cin, s);
    getline(cin, s);
    
    l %= mxN;
    for (char& c: s) {
        if (c==' ') continue;
        c = ((int)c+l<='z')? c+l:l-mxN+c;
    }
    cout<<s<<'\n';
    
    return 0;
    
}
