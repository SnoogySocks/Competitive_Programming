// 08/2020
// https://www.hackerrank.com/challenges/halloween-sale/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// n, k = 0; Ek
// 0+1+2+3
// m+m-1d+m-2d+m-3d
// n(p-((n-1)/2)d)
// pn-dn(n-1)/2 = s
// -dn^2+dn+2pn = 2s
// dn^2-(d+2p)n+2s = 0
// n = ((d+2p)-sqrt((d+2p)^2-4(d)(2s)))/2(d)

// Complete the howManyGames function below.
// int howManyGames(int p, int d, int m, int s) {
//     int a, b, c, max_n, sum_dec;
//     a = d, b = d+2*p, c = 2*s;
//     max_n = (p-m)/d+1;
//     sum_dec = max_n*(2*p-(max_n-1)*d)/2;
//     return (sum_dec>s)?(b-(int)ceil(sqrt(b*b-4*a*c)))/(2*a):max_n+(s-sum_dec)/m;
// }
int howManyGames(int p, int d, int m, int s) {
    int t = floor((p-m)/d);
    int r = (t+1)*(2*p-t*d)/2;
    if (p>s) return 0;
    return (r<=s)?(t+1)+(s-r)/m:(int)(d-sqrt(pow(d, 2)-4*-d*(4*p-2*s)))/(2*-d);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pdms_temp;
    getline(cin, pdms_temp);

    vector<string> pdms = split_string(pdms_temp);

    int p = stoi(pdms[0]);

    int d = stoi(pdms[1]);

    int m = stoi(pdms[2]);

    int s = stoi(pdms[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
