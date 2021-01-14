// https://dmoj.ca/problem/a3
// 1/2021

#include <bits/stdc++.h>

using namespace std;

const int s = 6;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    
    
    int a[s] { 0, 192, 442, 692, 942, 1192 };
    
    int t; scanf("%d", &t);
    while (t--) {
        int k; scanf("%d", &k);
        int i,j;
        i = k/1000*1000;
        j = k%1000;
        for (int l = s-2; l>=0; --l) {
            if (j>a[l]) {
                printf("%d\n", i+a[l+1]);
                break;
            }
        }
        
    }
    
    return 0;
}
