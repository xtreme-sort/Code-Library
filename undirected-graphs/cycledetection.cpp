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
    vector<int> vis(N, false);
    vector<int> previous(N, -1);

    for(int i = 0 ; i < M ; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool yes = false;
    int start = -1;
    int end = -1;
    
    function<void(int,int)> dfs = [&] (int u, int v) -> void {
        if(vis[u]) return;
        vis[u] = true;
        previous[u] = v;

        for(auto x : graph[u]){
            if(vis[x] and x != previous[u]){
                start = x;
                end = u;
                yes = true;
                return;
            }

            if(!vis[x]){
                dfs(x, u);
            }
            
            if(yes) return;
        }
    };

    for(int i = 0 ; i < N ; i++){
        if(!yes and !vis[i]) dfs(i, -1);
    }
    
    if(yes){
        stack<int> st;
        st.push(start);
        int x = end;
        while(x != previous[start]){
            st.push(x);
            x = previous[x];
        }
        cout << st.size() << endl;
        while(!st.empty()){
            cout << st.top() + 1 << " ";
            st.pop();
        }
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
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