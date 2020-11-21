// 08/2020
// https://www.hackerrank.com/challenges/separate-the-numbers/problem

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Complete the separateNumbers function below.
void separateNumbers(string s) {

    ll first;
    ll min = LLONG_MAX;
    string cur, actual;
    
    bool ok;
    int j;
    for (int i = 1; i<=s.size()/2&&min==LLONG_MAX; i++) {
        cur = s.substr(0, i);
        first = stoll(cur);
        if (min<=first) continue;
        ok = true;
        for (int j = i; j<s.size()&&ok; j+=cur.size()) {
            cur = to_string(stoll(cur)+1);
            if (cur!=s.substr(j, cur.size())) ok = false;
        }
        if (ok) min = first;
    }
    if (min==LLONG_MAX) {
        puts("NO");
    } else {
        printf("YES %lld\n", min);
    }

}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
