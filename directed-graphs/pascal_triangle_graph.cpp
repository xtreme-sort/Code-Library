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
    int N = 100;
    vector<vector<int>> grid(N), gridw(N);

    int node = 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < i + 1 ; j++){
            int x;
            cin >> x;
            gridw[i].push_back(x);
            grid[i].push_back(node);
            node++;
        }
    }

    int num = (N * (N + 1)) / 2;
    vector<vector<pair<int,int>>> graph(num + 1);

    for(int i = 0 ; i < N - 1 ; i++){
        for(int j = 0 ; j < i + 1 ; j++){
            graph[grid[i][j]].push_back({grid[i + 1][j], gridw[i + 1][j]});
            graph[grid[i][j]].push_back({grid[i + 1][j + 1], gridw[i + 1][j + 1]});
        }
    }
    vector<bool> vis(num + 1, false);
    
    vector<int> order;
    function<void(int)> dfs = [&](int u) {
        if(vis[u]) return;
        vis[u] = true;

        for(auto x : graph[u]){
            dfs(x.first);
        }
        order.push_back(u);
        return;
    };

    dfs(1);
    reverse(order.begin(), order.end());

    vector<int> dp(num + 1, -inf);

    dp[grid[0][0]] = gridw[0][0];

    for(auto x : order){
        for(auto y : graph[x]){
            dp[y.first] = max(dp[y.first], dp[x] + y.second);
        }
    }

    int ans = INT_MIN;
    for(auto x : grid[N - 1]){
        ans = max(ans, dp[x]);
    }
    cout << ans << endl;
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