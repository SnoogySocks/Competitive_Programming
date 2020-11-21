// 08/2020
// https://www.hackerrank.com/challenges/kaprekar-numbers/problem

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {

    int d = log10(p)+1;
    ll square;
    int ds;
    ll l, r;
    bool ok = false;
    while (p<=q) {

        l = r = 0;
        square = (ll)p*p;
        ds = log10(square)+1;
        for (ll i = powl(10, d-1), j = powl(10, ds-1), c = ds; 
            i>0; i/=10, j/=10, c--) {
            r = (r<<3)+(r<<1)+square/i%10;
            if (c>d) {
                l = (l<<3)+(l<<1)+square/j%10;
            }
        }
        if (r+l==p) {
            printf("%d ", p);
            ok = true;
        }
        if (++p%(int)pow(10, d)==0) d++;

    }
    if (!ok) {
        puts("INVALID RANGE");
    }
// 1 9 45 55 99 297 703 999 2223 2728 4950 5050 7272 7777 9999 17344 22222 77778 82656 95121 99999

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
