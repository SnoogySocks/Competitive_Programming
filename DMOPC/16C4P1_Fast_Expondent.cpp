// https://dmoj.ca/problem/dmopc16c4p1
// 7/2020

#include <bits/stdc++.h>

using namespace std;

template<typename T> void scan (T& u) {

	u = 0;
	bool neg = 0;
	T c = getchar();

	if (c == '-')
		neg = 1, c = getchar();

	// Clear console of non integer values
	for (; c < '0' || '9' < c; c = getchar());

	for (; '0' <= c && c <= '9'; c = getchar())
		u = (u << 3) + (u << 1) + (c & 15);

	if (neg) u *= -1;

}

int main() {
    
    int N; scan(N);
    
    for (int i = 0; i < N; i++) {
        long long n;
        scan(n);
        
        putchar(!(n&(n-1)) ? 'T' : 'F');
        putchar('\n');
    }
    
    return 0;
}
