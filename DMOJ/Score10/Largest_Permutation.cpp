// https://dmoj.ca/problem/largeperm
// 01/2021

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    
    int n,k; cin>>n>>k;
    
    if (k+1>=n) {
        for (int i = n; i>0; --i) {
            printf("%d ", i);
        }
        putchar('\n');
        return 0;
    }
    
    vector<int> pos(n+1);
    vector<int> mp(n+1);
    
    for (int i = 1; i<=n; ++i) {
        cin>>pos[i];
        mp[pos[i]] = i;
    }
    
    for (int top = 1; top<=n&&k; ++top) {
        int max = n-top+1;
        if (pos[top]!=max) {
            swap(pos[top], pos[mp[max]]);
            swap(mp[pos[top]], mp[pos[mp[max]]]);
            --k;
        }
    }
    
    for (int i = 1; i<=n; ++i) {
        printf("%d ", pos[i]);
    }
    putchar('\n');
    
    return 0;
    
}
