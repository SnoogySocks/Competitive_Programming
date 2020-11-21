// 08/2020
// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem

#include <bits/stdc++.h>

using namespace std;

int main() {

    int ans, n; scanf("%d", &n);
    int pos = 0;
    int c, p_c; scanf("%d%d", &p_c, &p_c);

    ans = 0;
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &c);
        if (pos==i) {
            if (p_c==0&&c==0||p_c==1) {
                pos += 2;
            } else if (p_c==0&&c==1) {
                pos++;
            }
            ans++;
        }
        p_c = c;
    }

    printf("%d", ans);

    return 0;
    
}
