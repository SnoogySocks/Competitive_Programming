// 08/2020
// https://www.hackerrank.com/challenges/append-and-delete/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    if (s.size()>t.size()) {
        string temp = s;
        s = t;
        t = temp;
    }

    string ans = "Yes";
    for (int i = 0; i < s.size(); i++) {
        if (s[i]!=t[i]&&s.size()+t.size()-2*i>k) {
            ans = "No";
            break;
        }
    }
    int difference = t.size()-s.size();
    if (k%2!=difference%2&&k<s.size()*2+difference) {
        ans = "No";
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
