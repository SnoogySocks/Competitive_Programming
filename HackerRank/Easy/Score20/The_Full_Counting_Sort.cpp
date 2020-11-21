// 08/2020
// https://www.hackerrank.com/challenges/countingsort4/problem

#include <bits/stdc++.h>

using namespace std;

template<typename T> void scan (T& n) {

    n = 0;
    bool neg = 0;
    T c = getchar();

    if (c=='-') neg = 1, c = getchar();

    // Clear console of non integer values
    for (; c<'0'||'9'<c; c = getchar());

    for (; '0'<=c&&c<='9'; c = getchar())
        n = (n<<3)+(n<<1)+(c&15);

    if (neg) n *= -1;

}
void scan (char* c, int length) {

    memset(c, 0, length);
    char buf;

    // Clear console of non alphanumeric values
    do buf = getchar();
    while ((buf<'0'||'9'<buf)
           &&(buf<'A'||'Z'<buf)
           &&(buf<'a'||'z'<buf));

    for (int i = 0; i<length-1
         &&(('0'<=buf&&buf<='9')
         ||('A'<=buf&&buf<='Z')
         ||('a'<=buf&&buf<='z'));
         buf = getchar())
        c[i++] = buf;

}

const int mxN = 100;

int main() {

    int n; cin >> n;
    vector<string> v[mxN];
    int idx;
    for (int i = 0; i<n/2; i++) {
        scan(idx);
        v[idx].push_back("-");
    }
    char c[11]{};
    for (int i = 0; i<n/2; i++) {
        scan(idx), scan(c, 11);
        v[idx].emplace_back(c);
    }

    for (auto vec : v) {
        for (string s: vec) {
            cout << s << ' ';
        }
    }
    putchar('\n');

    return 0;
    
}
