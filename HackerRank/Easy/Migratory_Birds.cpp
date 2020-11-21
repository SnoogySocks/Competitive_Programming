// 08/2020
#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    int birds[mxN]{};
    for (int i = 0; i < N; i++) {
        int bird; cin >> bird;
        birds[bird]++;
    }

    pair<int, int> max = make_pair(0, INT_MIN);
    for (int i = 0; i < N; i++) {
        if (max.second < birds[i] || max.first > i && max.second == birds[i]) {
            max = make_pair(i, birds[i]);
        }
    }
    cout << max.first << '\n';

    return 0;
    
}
