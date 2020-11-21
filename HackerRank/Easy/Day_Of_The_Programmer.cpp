// 08/2020
// https://www.hackerrank.com/challenges/day-of-the-programmer/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int day = 13;

// Complete the dayOfProgrammer function below.
void dayOfProgrammer(int year) {

    if (year <= 1917) {
        day -= year % 4 == 0;
    } else if (year != 1918) {
        day -= year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
    } else {
        day = 26;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    dayOfProgrammer(year);

    fout << day << ".09." << year << '\n';

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
