//
// https://dmoj.ca/problem/primes2
// Created by felix on 2021-12-26.
//

#include <bits/stdc++.h>

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
template<class T> void print (const vector<T>& v, char&& end = '\n') { for (const T& el: v) print(el, ' '); putchar(end); }
template<class T> void print (const vector<T>&& v, char&& end = '\n') { print(v); }

void solve () {

    int lo, hi; scan(lo, hi);
    if (hi==2 || lo<=2) {
        if (lo==1) lo = 2;
        print(2);
        if (hi==2) return;
    }

    // Correct the ranges
    lo -= lo%2==1;
    hi -= hi%2==0;

    // Find sieve under sqrt(hi)
    int n = (int) sqrt(hi)+1;
    int m = hi-lo+1;
    vec<bool> sieve(n/2), rangeSieve(m/2);

    for (int prime = 3; prime<n; prime += 2) {
        if (sieve[prime/2]) {
            continue;
        }
        // prime is prime so not marked
        for (int j = 3*prime; j<n; j += 2*prime) {
            sieve[j/2] = true;
        }

        // Find prime within range
        int j = (prime-lo%prime)%prime;
        if (j%2==0) {
            j += prime;
        } else if (lo+j==prime) {
            j += 2*prime;
        }
        for (; j<=m; j += 2*prime) {
            rangeSieve[j/2] = true;
        }
    }

    for (int i = 0; i<rangeSieve.size(); ++i) {
        if (!rangeSieve[i]) {
            print(lo+2*i+1);
        }
    }

}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}

