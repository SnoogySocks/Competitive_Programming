// https://www.hackerrank.com/challenges/making-anagrams/problem
// 02/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 26;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {

    vector<int> cnt(mxN);
    
    for (char c: s1) ++cnt[c-'a'];
    for (char c: s2) --cnt[c-'a'];
    
    int ans = 0;
    for (int i = 0; i<mxN; ++i) {
        ans += abs(cnt[i]);
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
