// 08/2020
// https://www.hackerrank.com/challenges/beautiful-binary-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {

    string bad = "010";
    int ans = 0;
    for (int i = 0; i<b.size()-2; i++) {
        bool m = true;
        for (int j = 0; j<bad.size(); j++) {
            m &= bad[j]==b[i+j];
        }
        if (m) {
            b[i+2] = '1';
            ans++;
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
