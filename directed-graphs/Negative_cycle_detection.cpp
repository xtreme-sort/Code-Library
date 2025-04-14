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

    vector<tuple<int,int,int>> graph;

    for(int i = 0 ; i < M ; i++){
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--; 
        graph.push_back({a, b, -x});
    }

    bool yes = false;
    vector<int> distance(N, inf);
    distance[0] = 0;
    for(int i = 0 ; i < N ; i++){
        for(auto e : graph){
            int a, b, w;
            tie(a, b, w) = e;
            if(distance[a] != inf and distance[a] + w < distance[b]){
                if(i == (N - 1)) yes = true;
                distance[b] = distance[a] + w;
            }
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;
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