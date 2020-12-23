// 12/23/2020
// https://dmoj.ca/problem/gfssoc1j5/resubmit/2225022

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
void scan (char* c, int size) {

	memset(c, 0, size);
	char buf;

	// Clear console of non alphanumeric values
	do {
		buf = getchar();
	} while ((buf < '0' || '9' < buf)
			 && (buf < 'A' || 'Z' < buf)
			 && (buf < 'a' || 'z' < buf));

	for (int i = 0; i < size - 1
		 && (('0' <= buf && buf <= '9')
			 || ('A' <= buf && buf <= 'Z')
			 || ('a' <= buf && buf <= 'z'));
		 buf = getchar())
		c[i++] = buf;

}

// Integers only
template<typename T> void print (T n, char&& end = '\n') {

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

const int mxN = 1001;

int N, M, T;
vector<int> adj[mxN]{};

void bfs (int a, int b, bool v[mxN], int d[mxN]) {

	queue<int> q;
	q.push(a);
	v[a] = 1;

	while (q.size()) {

		int r = q.front();
		q.pop();

		for (int i = 0; i<adj[r].size(); i++) {
			if (adj[r][i] == b) {
				print(T*(d[r]+1));
				return;
			} else if (!v[adj[r][i]]) {
				v[adj[r][i]] = 1;
				d[adj[r][i]] = d[r]+1;
				q.push(adj[r][i]);
			}
		}

	}
	puts("Not enough hallways!");

}

void solution() {

	scan(N); scan(M); scan(T);

	for (int i = 0; i<M; i++) {
		int a, b; scan(a), scan(b);
		adj[a].reserve(M);
		adj[a].push_back(b);
	}

	int Q; scan(Q);
	while (Q--) {
		bool v[mxN]{};
		int d[mxN]{};
		int a, b; scan(a), scan(b);
		
		bfs(a, b, v, d);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
#if 0
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
