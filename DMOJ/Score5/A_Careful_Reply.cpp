// https://dmoj.ca/problem/acmtryouts3b
// 1/2021

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i<s.size()-1; ++i) {
        ans += s[i]=='<'&&s[i+1]=='3';
    }
    for (int i = 0; i<=ans; ++i) {
        cout<<"<3 ";
    }
    cout<<'\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    
    string s;
    getline(cin, s);
    int t = stoi(s);
    while (t--) {
        solve();
    }
    
    return 0;
}
