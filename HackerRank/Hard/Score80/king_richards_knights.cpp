// https://www.hackerrank.com/challenges/king-richards-knights/problem
// October 27, 2022

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <climits>
#include <cassert>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define vec vector
#define all(x) begin(x), end(x)
#define square(x) ((x)*(x))

template<class T> static void scan (T& e) { e = 0; bool neg = false; char c = getchar(); for (; c<'0' || '9'<c; c = getchar()) if (c=='-') neg = true; for (; '0'<=c && c<='9'; c = getchar()) e = (e<<3)+(e<<1)+(c&15); if (neg) e *= -1; }
template<class T> static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }
static void scan (vector<char>& c, const char&& escape = ' ') { char buf; do buf = getchar(); while (buf<'!' || '~'<buf); int i; for (i = 0; buf!='\n' && buf!=escape; buf = getchar()) c[i++] = buf; }
template<class T, class U> static void scan (T& a, U& b) { scan(a); scan(b); }
template<class T, class U, class V> static void scan (T& a, U& b, V& c) { scan(a, b); scan(c); }
template<class T, class U, class V, class W> static void scan (T& a, U& b, V& c, W& d) { scan(a, b); scan(c, d); }
template<class T> static void print (T e, char&& end = '\n') { bool neg = false; if (e<0) neg = true, e *= -1; char snum[65]; int i = 0; do { snum[i++] = e%10+'0'; e /= 10; } while (e); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
static void print (char e, char&& end = '\n') { putchar(e); putchar(end); }
template<class T> void print (vector<T>& v, char&& end = '\n') { for (const T& el: v) print(el, ' '); putchar(end); }
template<class T> void print (vector<T>&& v, char&& end = '\n') { print(v); }

void rotate (vec<vec<int>>& matrix, vec<vec<int>>& transpose, int a, int b, int d) {
    // transpose the matrix
    for (int i = a; i<=a+d; ++i) {
        for (int j = b; j<=b+d; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Reflect the matrix
    for (int i = 0; i<=d; ++i) {
        for (int j = 0; j<=d; ++j) {
            matrix[a+i][b+j] = transpose[b+i][d+a-j];
            matrix[a+i][d+b-j] = transpose[b+i][a+j];
        }
    }
}

void solve () {

    int n, s; scan(n, s);
    vec<vec<int>> matrix(n, vec<int>(n));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            matrix[i][j] = i*n+j;
        }
    }

    vec<vec<int>> transpose(n, vec<int>(n));
    while (s--) {
        int a, b, d;
        scan(a, b, d);
        rotate(matrix, transpose, a-1, b-1, d);
    }

    vec<pii> soldier_pos(n*n);
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            soldier_pos[matrix[i][j]] = make_pair(i+1, j+1);
        }
    }

    int l; scan(l);
    while (l--) {
        int a; scan(a);
        auto [r, c] = soldier_pos[a];
        printf("%d %d\n", r, c);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
