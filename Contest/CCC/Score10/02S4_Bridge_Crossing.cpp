// https://dmoj.ca/problem/ccc02s4
// 02/2021

#include <vector>
#include <algorithm>

using namespace std;
#define all(x) begin(x), end(x)

const int mxN = 1e8;

int m, q;
vector<string> queue;
vector<int> segCrossingTime;

int getSlowest (int l, int r) {

    l += q, r += q+1;
    int slowest;
    for (slowest = 0; l<r; l >>= 1, r >>= 1) {
        if (l&1) slowest = max(slowest, segCrossingTime[l++]);
        if (r&1) slowest = max(slowest, segCrossingTime[--r]);
    }
    return slowest;

}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin>>m>>q;
    queue = vector<string>(q+1);
    segCrossingTime = vector<int>(2*(q+1));
    for (int i = 1; i<=q; ++i) {
        cin>>queue[i]>>segCrossingTime[i+q];
    }
    for (int i = q; i>1; --i) {
        segCrossingTime[i] = max(segCrossingTime[i<<1], segCrossingTime[i<<1|1]);
    }
    
    // Fastest time for the first q people
    vector<int> dp(q+1, mxN);
    vector<vector<vector<string>>> dq(q+1);
    dp[0] = 0;
    for (int totalP = 1; totalP<=q; ++totalP) {
        for (int lastP = max(0, totalP-m); lastP<totalP; ++lastP) {
            int slowest = getSlowest(lastP+1, totalP);
            if (dp[totalP]>dp[lastP]+slowest) {
                dp[totalP] = dp[lastP]+slowest;
                dq[totalP] = vector<vector<string>>(all(dq[lastP]));
                dq[totalP].emplace_back(queue.begin()+lastP+1, queue.begin()+totalP+1);
            }
        }
    }
    cout<<"Total Time: "<<dp[q]<<'\n';
    for (vector<string> v:dq[q]) {
        for (string s:v) {
            cout<<s<<' ';
        }
        cout<<'\n';
    }

    return 0;

}
