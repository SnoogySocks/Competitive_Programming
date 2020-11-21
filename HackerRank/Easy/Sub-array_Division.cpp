// 06/2020

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int mxN = 100;

void solution() {

    int n, s[mxN];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int d, m;
    cin >> d >> m;

    int sum = s[0];
    for (int i = 1; i < m; i++) {
        sum += s[i];
    }

    /*
      19
      2 5 1 3 4 4 3 5 1 1 2 1 4 1 3 3 4 2 1
      18 7
    */

    int n_ways = 0;
    int i = m;
    
    do {

        if (sum == d) {
            n_ways++;
        }
        sum -= s[i - m];
        sum += s[i++];

    } while (i < n);

    if (sum == d) {
        n_ways++;
    }
    
    cout << n_ways;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution();
    cout << '\n';

    return 0;

}
