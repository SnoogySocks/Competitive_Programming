// 08/2020
// https://www.hackerrank.com/challenges/encryption/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 9;

// Complete the encryption function below.
string encryption(string s) {

    double l = sqrt(s.size());
    int r = l;
    int c = ceil(l);
    if (r*c<s.size()) r = c;

    char ns[mxN][mxN+1]{};
    int nspaces = 0;
    for (int i = 0; i<s.size(); i++) {
        if (s[i]==' ') {
            nspaces++;
            continue;
        }
        ns[(i-nspaces)/c][(i-nspaces)%c] = s[i];
    }

    char enypt[mxN*(mxN+1)+1]{};
    int pos = 0;
    for (int j = 0; j<c; j++) {
        for (int i = 0; i<r&&ns[i][j]!='\0'; i++) {
            enypt[pos++] = ns[i][j];
        }
        enypt[pos++] = ' ';
    }
    
    return enypt;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
