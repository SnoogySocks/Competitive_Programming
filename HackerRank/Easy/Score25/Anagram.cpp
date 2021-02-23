// https://www.hackerrank.com/challenges/anagram/problem
// 12/2020

#include <bits/stdc++.h>

using namespace std;

#define umap unordered_map
const int mxN = 26;
// Complete the anagram function below.
int anagram(string s) {

    if (s.size()%2) return -1;
    
    int len = s.size()/2;
    umap<char, int> mp; mp.reserve(mxN);
    
    for (int i = 0; i<len; ++i) {
        ++mp[s[i]];
    }
    for (int i = len; i<s.size(); ++i) {
        --mp[s[i]];
    }
    int ans = 0;
    for (auto i: mp) {
        ans += abs(i.second);
    }
    return ans/2;

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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
