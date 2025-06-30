#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for(int i = 0 ; i < n - 1 ; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    function<int(int, bool)> bfs = [&](int u, bool distance){
        vector<int> dist(n, 0);
        vector<int> vis(n, false);
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto x : graph[v]){
                if(!vis[x]){
                    dist[x] = dist[v] + 1;
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        if(distance) return *max_element(dist.begin(), dist.end());
        else return (int)(max_element(dist.begin(), dist.end()) - dist.begin());
    };

    int v = bfs(0, false);
    int dist = bfs(0, true);

    cout << v << " " << dist << endl;

}