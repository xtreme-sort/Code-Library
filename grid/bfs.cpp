#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
typedef long long ll;
typedef ll* ptr;
typedef ll& refer;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;
const ll inf = 1e18;

long long binexp(long long a, long long b, long long m){
   a = a % m;
   long long res = 1;
   while (b > 0) {
     if (b & 1) res = res * a % m;
     a = a * a % m;
     b >>= 1;
   }
   return res;
}

ll mod(const ll &x, const ll &m) {
  return (x % m + m) % m;
}

ll floor_div(const ll &a, const ll &b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

ll ceil_div(const ll &a, const ll &b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

template<typename T_vector>
void array_input(T_vector &v, ll n) {
    for (ll i = 0; i < n; i++) {
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

void solve(){
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    pair<int, int> start, end;
    
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        for(int j = 0; j < M; j++){
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M, {-1, -1}));
    vector<vector<char>> direction(N, vector<char>(M, ' '));
    queue<pair<int, int>> q;
    
    q.push(start);
    vis[start.first][start.second] = true;
    
    bool found = false;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int cur_i = cur.first, cur_j = cur.second;

        if(cur_i == end.first && cur_j == end.second){
            found = true;
            break;
        }

        for(int d = 0; d < 4; d++){
            int ni = cur_i + dx[d], nj = cur_j + dy[d];
            if(ni >= 0 && ni < N && nj >= 0 && nj < M && !vis[ni][nj] && grid[ni][nj] != '#'){
                q.push({ni, nj});
                vis[ni][nj] = true;
                parent[ni][nj] = {cur_i, cur_j};
                direction[ni][nj] = dir[d];
            }
        }
    }

    if(found){
        string path;
        pair<int, int> cur = end;
        while(cur != start){
            path += direction[cur.first][cur.second];
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size() << "\n" << path << endl;
    } 
    else{
        cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}