#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> graph(N);

    for(int i = 0 ; i < N - 1 ; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> up(N, vector<int>(32, -1));
    vector<int> depth(N, 0);


    // DFS (to pre-compute)
    function<void(int, int)> dfs = [&](int u, int parent){
        up[u][0] = parent;
        
        for(int i = 1 ; i < 32 ; i++){
            if(up[u][i - 1] != -1) up[u][i] = up[up[u][i - 1]][i - 1];
            else break;
        }

        for(auto x : graph[u]){
            if(x == parent) continue;
            depth[x] = depth[u] + 1;
            dfs(x, u);
        }
    };

    dfs(0, -1);

    // Kth-ancestor of u
    function<void(int, int)> kth_ancestor = [&](int u, int k){
        for(int i = 0 ; i < 32 ; i++){
            if(k & (1LL << i)) u = up[u][i];
            if(u == -1) break;
        }

        return u;
    };


    // Least-common-ancestor of u and v
    function<int(int, int)> LCA = [&](int u, int v){
        if(depth[u] < depth[v]) swap(u, v);

        for(int i = 32 ; i >= 0 ; i--){
            if(depth[u] - (1LL << i) >= depth[v]){
                u = up[u][i];
            } 
        }

        if(u == v) return u;

        for(int i = 31 ; i >= 0 ; i--){
            if(up[u][i] != -1 and up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    };

}