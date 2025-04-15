#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'

// This gives lexicographically lowest topological sort

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);
    for(int i = 0 ; i < M ; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        indegree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0 ; i < N ; i++){
        if(indegree[i] == 0) pq.push(i);
    }

    vector<int> topsort;
    while(!pq.empty()){
        int vertex = pq.top();
        pq.pop();
        topsort.push_back(vertex);
        
        for(auto x : graph[vertex]){
            indegree[x]--;
            if(indegree[x] == 0) pq.push(x);
        }
    }

    if(topsort.size() != N) cout << "IMPOSSIBLE" << endl;
    else{
        for(auto x : topsort) cout << x + 1 << " ";
        cout << endl;
    }
    
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}