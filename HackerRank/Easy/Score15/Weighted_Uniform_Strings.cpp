// 08/2020
// https://www.hackerrank.com/challenges/weighted-uniform-string/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e7+1;

int main() {

    ios_base::sync_with_stdio(true); cin.tie(nullptr);
    string s;
    int n;
    cin >> s >> n;
    bool dp[mxN]{};
    int sum = s[0]-'a'+1;
    for (int i = 1; i<s.size(); i++) {
        dp[sum] = true;
        sum = (s[i-1]==s[i])*sum+s[i]-'a'+1;
    }
    dp[sum] = true;

    int q;
    while (n--) {
        cin >> q;
        puts(dp[q]?"Yes":"No");
    }

    return 0;
    
}
