// 08/2020
// https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    ll ans = 0, n, a = 0;
    string s;
    cin >> s >> n;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i]=='a') {
            ans++;
            a += i<n%s.size();
        }
    }
    ans = ans*(n/s.size())+a;
    
    printf("%lld", ans);

    return 0;
    // aba a
    // 4
}
