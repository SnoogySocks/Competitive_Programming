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

template<class T>
static void scan (T& e) {
    e = 0;
    bool neg = false;
    char c = getchar();
    if (c=='-') neg = true, c = getchar();
    for (; c<'0' || '9'<c; c = getchar());
    for (; '0'<=c && c<='9'; c = getchar()) e = (e<<3)+(e<<1)+(c&15);
    if (neg) e *= -1;
}

template<class T>
static void scan (vector<T>& v, const int&& start = 0) { for (int i = start; i<v.size(); ++i) scan(v[i]); }

static void scan (vector<char>& c, const char&& escape = ' ') {
    char buf;
    do buf = getchar(); while (buf<'!' || '~'<buf);
    int i;
    for (i = 0; buf!='\n' && buf!=escape; buf = getchar()) c[i++] = buf;
    c[i] = '\0';
}

template<class T, class U>
static void scan (T& a, U& b) {
    scan(a);
    scan(b);
}

template<class T, class U, class V>
static void scan (T& a, U& b, V& c) {
    scan(a, b);
    scan(c);
}

template<class T, class U, class V, class W>
static void scan (T& a, U& b, V& c, W& d) {
    scan(a, b);
    scan(c, d);
}

template<class T>
static void print (T e, char&& end = '\n') {
    bool neg = false;
    if (e<0) neg = true, e *= -1;
    char snum[65];
    int i = 0;
    do {
        snum[i++] = e%10+'0';
        e /= 10;
    } while (e);
    i--;
    if (neg) putchar('-');
    while (i>=0) putchar(snum[i--]);
    putchar(end);
}

static void print (char e, char&& end = '\n') {
    putchar(e);
    putchar(end);
}

template<class T>
void print (vector<T>& v, char&& end = '\n') {
    for (const T& el: v) print(el, ' ');
    putchar(end);
}

template<class T>
void print (vector<T>&& v, char&& end = '\n') { print(v); }


const int mxN = 1000;
const int log2_1000 = 10;
int log2s[mxN+1] {};
int table[log2_1000][mxN][log2_1000][mxN] {};

void init (vec<vec<int>> arr) {
    // Preprocess the log 2s
//    log2s = vec<int>(max(arr.n(), arr[0].n())+1);
    int n = (int) arr.size();
    for (int i = 2; i<=n; ++i) {
        log2s[i] = log2s[i/2]+1;
    }

    // Copy input over to the table
//    table = vec<vec<vec<vec<int>>>>(
//            (int) log2(arr.n())+1, vec<vec<vec<int>>>(
//                    arr.n(), vec<vec<int>>(
//                            (int) log2(arr[0].n())+1, vec<int>(
//                                    arr[0].n()
//                            ))));
    int log2_n = (int) log2(n)+1;
    for (int i = 0; i<arr.size(); ++i) {
        for (int j = 0; j<arr[0].size(); ++j) {
            table[0][i][0][j] = arr[i][j];
        }
        // Create each 1D sparse table
        auto& cur = table[0][i];
        for (int power = 1; power<log2_n; ++power) {
            int prevPower = power-1;
            for (int j = 0; j+(1<<power)<=n; ++j) {
                cur[power][j] = min(cur[prevPower][j], cur[prevPower][j+(1<<prevPower)]);
            }
        }
    }

    for (int iPower = 1; iPower<log2_n; ++iPower) {
        int prevPower = iPower-1;
        for (int i = 0; i+(1<<iPower)<=n; ++i) {
            for (int jPower = 0; jPower<log2_n; ++jPower) {
                for (int j = 0; j<n; ++j) {
                    // Find the minimum of the rectangle made at coord
                    // (i, j) with a height of iPower and width of jPower
                    // By taking the min of 1 previous rectangle at the
                    // same coords but half the height and same width
                    // and the rectangle with the same dimensions directly
                    // below it.
                    table[iPower][i][jPower][j] = min(table[prevPower][i][jPower][j],
                                                      table[prevPower][i+(1<<prevPower)][jPower][j]);
                }
            }
        }
    }
}

int query (int u, int d, int l, int r) {
    int powerY = log2s[d-u+1];
    int powerX = log2s[r-l+1];
    int lenY = (1<<powerY)-1;
    int lenX = (1<<powerX)-1;
    int minRow1 = min(table[powerY][u][powerX][l], table[powerY][u][powerX][r-lenX]);
    int minRow2 = min(table[powerY][d-lenY][powerX][l], table[powerY][d-lenY][powerX][r-lenX]);

    return min(minRow1, minRow2);
