// 1/2020
// https://dmoj.ca/problem/nccc6j4

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int mxA = 26;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string food = "DBSR";
    int map[mxA] {};
    pair<int, int> orders[4] {}; // first = # of orders, second = type of food
    for (int i = 0; i<food.size(); ++i) {
        map[food[i]-'A'] = i;
        orders[i].second = food[i];
    }

    string s;
    int n;
    getline(cin, s);
    n = stoi(s);

    while (n--) {
        getline(cin, s);
        ++orders[map[s[0]-'A']].first;
    }

    sort(orders, orders+4, [map](pair<int, int> p1, pair<int, int> p2) {
        return p1.first>p2.first||(p1.first==p2.first&&map[p1.second-'A']<map[p2.second-'A']);
        });

    for (pair<int,int> t:orders) {
        if (t.first==0) continue;
        switch (t.second) {
            case 'D': s = "Deluxe Tuna Bitz"; break;
            case 'B': s = "Bonito Bitz"; break;
            case 'S': s = "Sashimi"; break;
            case 'R': s = "Ritzy Bitz"; break;
            default: s = "Something wrong occured";
        }
        cout<<s<<' '<<t.first<<'\n';
    }
    
    return 0;

}
