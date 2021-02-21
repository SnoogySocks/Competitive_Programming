// https://www.hackerrank.com/challenges/palindrome-index/problem
// 12/2020

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int is_palin (string &s) {
    for (int i = 0; i<s.size()/2; ++i) {
        if (s[i]!=s[s.size()-1-i]) return i;
    }
    return -1;
}

// Complete the palindromeIndex function below.
int palindromeIndex(string& s) {

    int x = is_palin(s);
    if (x==-1) return -1;
    s.erase(is_palin(s), 1);
    return is_palin(s)==-1? x:s.size()-x;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
