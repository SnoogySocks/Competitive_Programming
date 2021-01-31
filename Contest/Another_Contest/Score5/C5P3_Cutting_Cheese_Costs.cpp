// https://dmoj.ca/problem/acc5p3
// 01/2021

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar())n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }

void solve() {
    
    int n,k; scan(n); scan(k);
    vector<int> cheese; cheese.reserve(n);
    int d,p;
    ll sum = 0;
    for (int i = 0; i<n; ++i) {
        scan(p); scan(d);
        sum += p;
        cheese.push_back(d-p);
    }
    sort(cheese.begin(), cheese.end());
    for (int i = 0; i<k; ++i) {
        sum += cheese[i];
    }
    print(sum);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
