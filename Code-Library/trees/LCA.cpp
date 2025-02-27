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

const int MAX_SIZE = 1e5 + 5;

void solve(){
    int N;
    cin>>N;

    vector<int> tree[MAX_SIZE];

    for(int i = 0; i < N-1 ;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int x,y;
    cin>>x>>y;

    vector<int> parent(MAX_SIZE);
    function<void(int,int)> dfs = [&] (int v,int p){
        parent[v] = p;

        for(auto child : tree[v]){
            if(child == p) continue;
            dfs(child,v);
        }
    };


    function<vector<int>(int)> path = [&] (int v){
        vector<int> arr;

        while(v!=-1){
            arr.push_back(v);
            v=parent[v];
        }
        reverse(arr.begin(),arr.end());
        return arr;
    };  

    dfs(1,-1);
    
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int i=0,j=0;

    int ans=-1;
    while(i<path_x.size() and j<path_y.size()){
        if(path_x[i]==path_y[j]){
            ans=path_x[i];
        }
        i++;
        j++;
    }

    cout<<ans<<endl;

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