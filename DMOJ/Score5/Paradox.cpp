// https://dmoj.ca/problem/bts16p2
// 1/2021

#include <iostream>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout<<boolalpha;
    
    int s[2] { -1,-1 };
    int n; cin>>n;
    
    while (n--) {
        int i;
        string st;
        cin>>i;
        if (i!=4) cin>>st;
        bool j = st[0]=='t';
        switch (i) {
            case 1:
                cout<<(s[j]!=j);
                if (s[j]!=j) {
                    s[j] = j;
                }
                break;
            case 2:
                cout<<(s[j]==j);
                if (s[j]==j) {
                    s[j] = -1;
                }
                break;
            case 3:
                cout<<s[j];
                break;
            case 4:
                if (s[0]!=-1) cout<<(bool)s[0]<<' ';
                if (s[1]!=-1) cout<<(bool)s[1];
                break;
        }
        cout<<'\n';
    }
    
    return 0;
    
}
