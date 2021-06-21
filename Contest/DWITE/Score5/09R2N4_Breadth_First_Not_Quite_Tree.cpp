// https://dmoj.ca/problem/dwite09c2p4
// 11/2020

#include <iostream>
#include <vector>
#include <queue>

const int mxN = 101;

void solve() {

    int n; std::cin>>n;
    std::vector<int> adj[mxN] {};
    for (int i = 0; i<n; ++i) {
        int u, v; std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool v[mxN] {};
    int d[mxN] {};
    std::queue<int> q;
    q.push(1);
    v[1] = true;
    int cnt = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int x:adj[u]) {
            if (v[x]) {
                if (d[x]==d[u]) ++cnt;
                continue;
            }
            v[x] = true;
            d[x] = d[u]+1;
            q.push(x);
        }
    }
    std::cout<<cnt/2<<'\n';

}

int main() {
	
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    for (int t = 0; t<5; ++t) {
        solve();
    }
		
	return 0;

}
