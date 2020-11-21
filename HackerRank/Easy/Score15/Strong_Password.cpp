// 08/2020
// https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

/*
! = 33
# = 35
$ = 36
% = 37
& = 38
( = 40
) = 41
* = 42
+ = 43
- = 45
@ = 64
^ = 94
*/

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string schars = "!@#$%^&*()-+";
    int ans = 0;
    bool ok[4]{};
    for (char c: password) {
        ok[0] |= isdigit(c);
        ok[1] |= islower(c);
        ok[2] |= isupper(c);
        // for (int i = 0; i<schars.size(); i++) {
        //     ok[3] |= schars.find(c)!=string::npos;
        // }
        ok[3] |= '!'<=c&&c<='-'||c=='@'||c=='^';
    }
    for (int i = 0; i<4; i++) {
        ans += !ok[i];
    }
    if (n+ans<6) ans += 6-n-ans;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
