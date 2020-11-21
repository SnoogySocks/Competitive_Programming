// 05/2020
// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int num_v = 0;
    int cur_lvl = 0;
    int prev_lvl = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s.at(i) == 'D') {
            cur_lvl--;
        } else {
            cur_lvl++;
        }
        if (prev_lvl == 0 && cur_lvl == -1) {
            num_v++;
        }
        prev_lvl = cur_lvl;
    }
    return num_v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
