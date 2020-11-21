// 08/2020
// https://www.hackerrank.com/challenges/two-characters/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1001;
const int nletrs = 26;

int main() {

    int len;
    char s[mxN];
    scanf("%d%s", &len, s);
    s[len] = 0;
    
    int nm, nf, ns;
    nm = 0;
    bool v[nletrs]{};
    for (int i = 0; i<len; i++) {
        if (v[s[i]-'a']) continue;
        for (int j = i+1; s[i]!=s[j]&&j<len; j++) {
            if (v[s[j]-'a']) continue;
            nf = ns = 0;
            bool ok = true;
            for (int k = i; k<len; k++) {
                if (v[s[i]-'a']) continue;
                if (s[i]==s[k]) {
                    if (nf>ns) {
                        ok = false;
                        break;
                    }
                    nf++;
                } else if (s[j]==s[k]) {
                    if (nf<=ns) {
                        ok = false;
                        break;
                    }
                    ns++;
                }
            }
            if (ok&&nm<nf+ns) {
                nm = nf+ns;
            }
        }
        v[s[i]-'a'] = true;
    }

    printf("%d", nm);
    
    return 0;
    
}
