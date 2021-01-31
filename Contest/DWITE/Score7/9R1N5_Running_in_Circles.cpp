// 5/2020
// https://dmoj.ca/problem/dwite09c1p5

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
#include <cstring>

using namespace std;
typedef long long ll;
#define s_cast static_cast
#define u_set unordered_set
#define u_map unordered_map
#define p_queue priority_queue

// Integers only
template<typename T> void scan (T& u);
template<typename T> void print (T u, char&& end = '\n');

template<typename T> T gcf (T a, T b);
template<typename T> T lcm (T a, T b);

const int mxN = 101;

void dfs (int u, bool& found_c, vector<int> adj[mxN], int d[mxN], char v[mxN]) {

	v[u] = 1;

	for (int i = 0; i < adj[u].size() && !found_c; i++) {
		
		if (v[adj[u][i]] == 1) {
			found_c = 1;
			print(d[u] + 1 - d[adj[u][i]]);
		} else if (v[adj[u][i]] == 0) {
			d[adj[u][i]] = d[u] + 1;
			dfs(adj[u][i], found_c, adj, d, v);
		}

	}

	v[u] = 2;

}

void solution() {

	int N;
	scan(N);

	vector<int> adj[mxN];
	char v[mxN];
	int d[mxN];

	for (int i = 0; i < N; i++) {
		int f; scan(f);
		int s; scan(s);
		adj[f].push_back(s);
	}
	memset(v, 0, mxN);
	memset(d, 0, 4 * mxN);

	bool found_c = 0;
	dfs(1, found_c, adj, d, v);

}

int main() {

	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
#if 1
	/*int n_tests;
	scan(n_tests);*/

	for (int i = 0; i < 5; i++) {
		solution();
	}
#else
	solution();
#endif

	return 0;

}

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
template<typename T> void print (T u, char&& end) {

	bool neg = 0;

	if (u < 0)
		neg = 1, u *= -1;

	char snum[65];
	int i = 0;
	do {
		snum[i++] = u % 10 + '0';
		u /= 10;
	} while (u);
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
