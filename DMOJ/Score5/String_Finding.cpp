// https://dmoj.ca/problem/bf4
// 1/2021

#include <bits/stdc++.h>

using namespace std;

vector<int> lps;

void computerLPS (string& s) {
    
    int len;
    len = lps[0] = 0;
    
    int i = 1;
    while (i<s.size()) {
        if (s[i]==s[len]) {
            lps[i++] = ++len;
        } else {
            if (len!=0) {
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    string txt, pat;
    cin>>txt>>pat;
    
    lps = vector<int>(pat.size());
    computerLPS(pat);
    
    int i,j;
    i = j = 0;
    while (i<txt.size()) {
        if (pat[j]==txt[i]) {
            ++j, ++i;
        }
        if (j==pat.size()) {
            cout<<(i-j)<<'\n';
            return 0;
        } else if (i<txt.size()&&pat[j]!=txt[i]) {
            if (j!=0) {
                j = lps[j-1];
            } else {
                ++i;
            }
        }
    }
    cout<<-1<<'\n';
    
    return 0;
    
}
