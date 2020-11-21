// 08/2020
// https://www.hackerrank.com/challenges/strange-code/problem

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
v(x) = 3(2)^(x-1)
where x is the cycle number

T(x) = 3(2^x)
x = log2(t/3+(t%3!=0))
v(T(x)) = T(x)-(t-T(x)+3)+1
        = 2T(x)-t-2
*/

int main() {

    ll t; scanf("%lld", &t);
    ll x = t/3+(t%3!=0);
    for (ll i = 1; x+1&x; i <<= 1) {
        x |= x>>i;
    }
    x = x+1>>1;
    printf("%lld", 6*x-t-2);
    
}
