// 7/2020
// https://dmoj.ca/problem/ccc14s3

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
#define s_cast static_cast
#define u_set unordered_set
#define u_map unordered_map
#define p_queue priority_queue

// Integers only
template<typename T> void scan (T& n);
template<typename T> void print (T n, char&& end = '\n');

const int mxN = 1e5;
int carts[mxN];
int branch[mxN];

void solution() {

    int N; scan(N);
	for (int i = 0; i < N; i++) {
		scan(carts[i]);
	}

    int top = -1;
	bool ok = 1;
	int next_c = 1;

	for (int i = N - 1; i >= -1 && ok; i--) {

		while (top+1 && branch[top] == next_c) {
            top--;
			next_c++;
		}

		if (i >= 0 && carts[i] == next_c) {
			next_c++;
		} else if (i >= 0) {
            branch[++top] = carts[i];
		} else if (next_c != N + 1) {
			ok = 0;
		}

	}

    putchar((ok) ? 'Y' : 'N');
    putchar('\n');

}

int main() {

	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
#if 1
	int n_tests;
	scan(n_tests);

	for (int i = 0; i < n_tests; i++) {
		solution();
	}
#else
	solution();
#endif

	return 0;

}

template<typename T> void scan (T& n) {

	n = 0;
	bool neg = 0;
	T c = getchar();

	if (c == '-')
		neg = 1, c = getchar();

	// Clear console of non integer values
	for (; c < '0' || '9' < c; c = getchar());

	for (; '0' <= c && c <= '9'; c = getchar())
		n = (n << 3) + (n << 1) + (c & 15);

	if (neg) n *= -1;

}
template<typename T> void print (T n, char&& end) {

	bool neg = 0;

	if (n < 0)
		neg = 1, n *= -1;

	char snum[65];
	int i = 0;
	do {
		snum[i++] = n % 10 + '0';
		n /= 10;
	} while (n);
	i--;

	if (neg)
		putchar('-');

	while (i >= 0)
		putchar(snum[i--]);

	putchar(end);

}

template<typename T> T gcf (T a, T b) {

	while (a != 0) {
		int temp = a;
		a = b % a;
		b = temp;
	}
	return b;

}
template<typename T> T lcm (T a, T b) {
	return (a * b) / gcf(a, b);
}
