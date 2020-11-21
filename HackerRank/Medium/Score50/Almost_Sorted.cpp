#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+2;

int main() {

    int n; scanf("%d", &n);
    int a[mxN];
    a[0] = -1;
    for (int i = 1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    a[n+1] = 1e6+1;
    int i, j;
    j = 0;
    for (i = 1; i<n; i++) {
        if (a[i]>a[i+1]) {
            j = i;
            break;
        }
    }
    if (j==0) {
        puts("yes");
        return 0;
    }
    
    int k, c;
    bool r, isswap;
    r = 1;
    c = 0;
    for (; i<=n; i++) {
        if (a[i]>a[i+1]&&!r) {
            c++;
            k = i+1;
        } else if (a[i]<a[i+1]&&r) {
            c++;
            isswap = i-j==1;
            k = i;
            r = 0;
        }
    }

    if (isswap) swap(a[j], a[k]);
    if ((isswap&&k-j!=1?c>2:c>1)||!(isswap?a[j-1]<a[j]&&a[j]<a[j+1]&&a[k-1]<a[k]&&a[k]<a[k+1]:a[j-1]<a[k]&&a[j]<a[k+1])) {
        puts("no");
    } else {
        printf("yes\n%s %d %d\n", isswap?"swap":"reverse", j, k);
    }
    
    return 0;
    
}
