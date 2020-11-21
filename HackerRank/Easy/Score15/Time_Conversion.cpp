// 06/2020
// https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */

    string m;

    bool isTwelve = s.at(0) == '1' && s.at(1) == '2';

    if (s.at(8) == 'A' || isTwelve) {
        if (isTwelve && s.at(8) == 'A') {
            m = "00";
        } else {
            m = string(s, 0, 2);
        }
    } else {
        if (s.at(0) == '1') {
            m = to_string(s.at(1) - 26);
        } else {
            m = to_string(s.at(1) - 36);
        }
    }
    m += ":" + string(s, 3, 5);
    return m;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
