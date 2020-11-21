// 08/2020
// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

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

template<typename T> void scan (T& n);
void scan (char* c, int size);

//Integers only
template<typename T> void print (T n, char&& end = '\n');

const int mxN = 20e5+2;
ll scores[mxN] {};

void solution() {

    int n, m;
    scan(n);

    int input; scan(input);
    scores[1] = input;

    int rank = 1;
    for (int i = 1; i<n; i++) {
        scan(input);
        if (input!=scores[rank]) scores[++rank] = input;
    }
    
    scan(m);
    scores[0] = 10e9+1;
    scores[rank+1] = -1;

    for (int i = 0; i<m; i++) {
        scan(input);
        while (scores[rank]<input) rank--;
        print(scores[rank]!=input ? rank+1 : rank);
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

template<typename T> void scan (T& n) {

    n = 0;
    bool neg = 0;
    T c = getchar();

    if (c=='-')
        neg = 1, c = getchar();

    // Clear console of non integer values
    for (; c<'0'||'9'<c; c = getchar());

    for (; '0'<=c&&c<='9'; c = getchar())
        n = (n<<3)+(n<<1)+(c&15);

    if (neg) n *= -1;

}
void scan (char* c, int size) {

    memset(c, 0, size);
    char buf;

    // Clear console of non alphanumeric values
    do {
        buf = getchar();
    } while ((buf<'0'||'9'<buf)
             &&(buf<'A'||'Z'<buf)
             &&(buf<'a'||'z'<buf));

    for (int i = 0; i<size-1
         &&(('0'<=buf&&buf<='9')
            ||('A'<=buf&&buf<='Z')
            ||('a'<=buf&&buf<='z'));
         buf = getchar())
        c[i++] = buf;

}
template<typename T> void print (T n, char&& end) {

    bool neg = 0;

    if (n<0)
        neg = 1, n *= -1;

    char snum[65];
    int i = 0;
    do {
        snum[i++] = n%10+'0';
        n /= 10;
    } while (n);
    i--;

    if (neg)
        putchar('-');

    while (i>=0)
        putchar(snum[i--]);

    putchar(end);

}
