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

    vector<string> grid(N);

    for(auto &x : grid){
        cin >> x;
    }

    vector<pair<int,int>> monsters;
    pair<int,int> start;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(grid[i][j] == 'M') monsters.push_back({i, j});
            if(grid[i][j] == 'A') start = {i, j};
        }
    }
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<char> dir = {'D', 'U', 'L', 'R'};

    vector<vector<int>> monster_time(N, vector<int>(M, inf));
    queue<pair<int, int>> q_monsters;

    auto bfs_monsters = [&](){
        for(auto &monster : monsters){
            q_monsters.push(monster);
            monster_time[monster.first][monster.second] = 0;
        }

        while(!q_monsters.empty()){
            pair<int,int> p = q_monsters.front(); 
            q_monsters.pop();

            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] != '#' && monster_time[nx][ny] == inf){
                    monster_time[nx][ny] = monster_time[x][y] + 1;
                    q_monsters.push({nx, ny});
                }
            }
        }
    };

    bfs_monsters();

    vector<vector<int>> player_time(N, vector<int>(M, inf));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M, {-1, -1}));
    vector<vector<char>> direction(N, vector<char>(M, ' '));
    queue<pair<int, int>> q_player;

    q_player.push(start);
    player_time[start.first][start.second] = 0;

    bool found = false;
    pair<int, int> end;

    while(!q_player.empty()){
        auto p = q_player.front(); 
        q_player.pop();

        int x = p.first;
        int y = p.second;

        if(x == 0 or x == N - 1 or y == 0 or y == M - 1){
            found = true;
            end = {x, y};
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] != '#' &&
                player_time[nx][ny] == inf && player_time[x][y] + 1 < monster_time[nx][ny]){
                player_time[nx][ny] = player_time[x][y] + 1;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = dir[i];
                q_player.push({nx, ny});
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