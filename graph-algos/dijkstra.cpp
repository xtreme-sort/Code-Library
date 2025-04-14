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
 

// This is for directed graph
// Change the input for making it undirected 
void solve() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<pair<int,int>>> graph(N);
 
    for(int i = 0 ; i < M ; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        graph[u].push_back({v,c});
    }
 
    vector<int> D(N, inf);
    vector<int> processed(N, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, 0));
    D[0] = 0;
    
    while(!pq.empty()){
        pair<int,int> vertex = pq.top();
        pq.pop();

        if(processed[vertex.second]) continue;
        processed[vertex.second] = true;

        for(auto x : graph[vertex.second]){
            if(x.second + vertex.first < D[x.first]){
                pq.push(make_pair(x.second + vertex.first , x.first));
                D[x.first] = x.second + vertex.first;
            }
        }
    }  
 
    array_output(D);
 
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