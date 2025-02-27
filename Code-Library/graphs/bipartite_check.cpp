#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'


int binexp(int a, int b, int m) {
    a = a % m;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int mod(const int &x, const int &m) {
    return (x % m + m) % m;
}

int floor_div(const int &a, const int &b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

int ceil_div(const int &a, const int &b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

template<typename T_vector>
void array_input(T_vector &v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

template<typename T_vector>
void array_output(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int MOD = 1000000007;
const int inf = 1e18;
const int MAX_SIZE = 1e5 + 5;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);

    for(int i  = 0 ; i < M ; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    vector<bool> vis(N,false);
    vector<int> color(N);

    bool yes = true;

    function<void(int,int)> dfs = [&](int u, int v){

        vis[u] = true;
        color[u] = 1 - color[v];
        for(auto child : graph[u]){
            if(vis[child]){
                if(color[child] == color[u]){
                    yes = false;
                }
                continue;
            }
            dfs(child,u);
        }
        return;
    };


    color[0] = 1;
    dfs(0,0);

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;



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