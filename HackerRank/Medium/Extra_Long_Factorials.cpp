// 08/2020
// https://www.hackerrank.com/challenges/extra-long-factorials/problem

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
#include <forward_list>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define s_cast static_cast
#define f_list forward_list
#define u_set unordered_set
#define u_map unordered_map
#define p_queue priority_queue

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
void scan (char* c, int length) {

    memset(c, 0, length);
    char buf;

    // Clear console of non alphanumeric values
    do {
        buf = getchar();
    } while ((buf<'0'||'9'<buf)
             &&(buf<'A'||'Z'<buf)
             &&(buf<'a'||'z'<buf));

    for (int i = 0; i<length-1
         &&(('0'<=buf&&buf<='9')
            ||('A'<=buf&&buf<='Z')
            ||('a'<=buf&&buf<='z'));
         buf = getchar())
        c[i++] = buf;

}

//Integers only
template<typename T> void print (T n, char&& end = '\n') {

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

const size_t mxN = 9;
const ull mxull = 1e19;
// 10000000000000000000
// 

const size_t mxDigits = 19;

struct BigInt {

    array<ull, mxN> number;
    size_t g_index;

    BigInt() : number(), g_index(0) {}
    BigInt(ull num) : number(), g_index(0) { 
        number[0] = num;
        if (num<mxull) g_index = 0;
        else {
            g_index = 1;
            number[0] = num-mxull;
            number[1] = 1;
        }
    }
    BigInt (array<ull, mxN> number, size_t curIndex) {
        this->number = number;
        this->g_index = curIndex;
    }
    BigInt (BigInt& copy) : BigInt() {
        g_index = copy.g_index;
        for (int i = 0; i<=g_index; i++) {
            number[i] = copy[i];
        }
    }
    ~BigInt() {}
    void add (BigInt num) {

        bool has_r = false;
        for (int i = 0; i<=num.g_index; i++) {
            if (mxull-number[i]<=num[i]+has_r) {
                number[i] = num[i]+has_r-(mxull-number[i]);
                has_r = true;
            } else {
                number[i] += num[i]+has_r;
                has_r = false;
            }
        }

        if (g_index<num.g_index) g_index = num.g_index;
        for (int i = num.g_index+1; has_r;) {
            number[i]++;
            if (number[i]==1&&g_index<i) {
                g_index = i;
                break;
            } else if (number[i]==mxull) {
                number[i++] = 0;
            } else {
                break;
            }
        }

    }
    void multiply (size_t n) {
        BigInt num(*this);
        clear();
        for (int i = 0; i<n; i++) {
            add(num);
        }
    }

    void clear() {
        while (g_index) number[g_index--] = 0;
        number[0] = 0;
    }

    void display() {
        
        printf("%llu", number[g_index]);
        for (int i = g_index-1; i>=0; i--) {
            if (number[i]) printf("%019llu", number[i]);
            else printf("0000000000000000000");
        }
        putchar('\n');

    }
    ull& operator[] (size_t i) {
        return number[i];
    }

};

BigInt factorial (int n) {
    BigInt f(1);
    while (n) {
        f.multiply(n--);
    }
    return f;
}

void solution() {

    int n; scan(n);
    //BigInt a(array<ull, mxN> {mxull-1, mxull-1}, 1);
    factorial(n).display();
    
}

int main() {

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#if 0
    int n_tests;
    scan(n_tests);

    for (int i = 0; i<n_tests; i++) {
        solution();
    }
#else
    solution();
#endif

    return 0;

}
