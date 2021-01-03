// https://dmoj.ca/problem/cco99p2
// 1/2021

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve (int k, unordered_map<string, int>& freq) {

    vector<pair<string, int>> v; v.reserve(freq.size());
    copy(freq.begin(), freq.end(), back_inserter(v));
    sort(v.begin(), v.end(), [](pair<string, int>& p1, pair<string, int>& p2) -> bool {
        return p1.second>p2.second;
    });

    if (k!=1&&v[k-2].second==v[k-1].second) return;
    for (int i = k-1; i<v.size()&&v[k-1].second==v[i].second; ++i) {
        cout<<v[i].first<<'\n';
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t; cin>>t;
    for (int i = 1; i<=t; ++i) {
        int m, k; cin>>m>>k;
        unordered_map<string, int> freq; freq.reserve(m);
        string s;

        for (int i = 0; i<m; ++i) {
            cin>>s;
            ++freq[s];
        }

        cout<<k;
        if (11<=k%100&&k%100<=13) cout<<"th";
        else switch (k%10) {
            case 1: cout<<"st"; break;
            case 2: cout<<"nd"; break;
            case 3: cout<<"rd"; break;
            default: cout<<"th";
        }
        cout<<" most common word(s):"<<'\n';
        if (k<=m) solve(k, freq);
        putchar('\n');
    }

    return 0;

}
