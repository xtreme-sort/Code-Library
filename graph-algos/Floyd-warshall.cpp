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


// For undirected - graph
void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for(int i = 0 ; i < M ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(graph[a][b]) graph[a][b] = min(graph[a][b], c);
        else graph[a][b] = c;
        if(graph[b][a]) graph[b][a] = min(graph[b][a], c);
        else graph[b][a] = c;
    }                   
    
    vector<vector<int>> dp(N, vector<int>(N));

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i == j) dp[i][j] = 0;
            else if(graph[i][j]) dp[i][j] = graph[i][j];
            else dp[i][j] = inf;
        }
    }

    for(int k = 0 ; k < N ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(Q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dp[a][b] == inf) cout << -1 << endl;
        else cout << dp[a][b] << endl;
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