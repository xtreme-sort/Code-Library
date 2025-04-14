#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'

const int MOD = 1000000007;
const int inf = 1e18;
const int MAX_SIZE = 1e5 + 5;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> graph(N);

    for(int i = 0 ; i < M ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({b, w});
    }

    int num_states = 2;
    vector<vector<int>> dist(N, vector<int>(num_states, inf));
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto ver = pq.top();
        pq.pop();
    
        int cur = ver[0];
        int u = ver[1];
        int used = ver[2];

        if(cur > dist[u][used]) continue;

        for(auto x : graph[u]){
            int v = x.first;
            int w = x.second;

            if(dist[v][used] > dist[u][used] + w){
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }

            if(used == 0 and dist[v][1] > dist[u][0] + w){
                dist[v][1] = dist[u][0] + w;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[N-1][0], dist[N-1][1]) << endl;

}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}