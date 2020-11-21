// 08/2020
// https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 101;

void pigeonsort (char (&a)[mxN], int j, int l) {

    char buf[26] {};
    for (int i = j; i<l; i++) {
        buf[a[i]-'a']++;
    }
    for (int i = 0; i<26; i++) {
        if (buf[i]==0) continue;
        while (buf[i]-->0) {
            a[j++] = i+'a';
        }
    }

}

void solve() {

    char buf[mxN] {};
    scanf("%s", buf);
    int l = 0;
    while (buf[l++]);
    l -= 2;

    int p1, p2;
    p1 = -1;
    for (int i = l; i>p1; i--) {
        for (int j = i-1; j>p1; j--) {
            if (buf[j]<buf[i]&&p1<j) {
                p1 = j, p2 = i;
                break;
            }
        }
    }

    if (p1==-1) {
        puts("no answer");
        return;
    }
    buf[p1] ^= buf[p2];
    buf[p2] ^= buf[p1];
    buf[p1] ^= buf[p2];
    pigeonsort(buf, p1+1, l+1);
    puts(buf);
    
}
int main() {

    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
    
}
