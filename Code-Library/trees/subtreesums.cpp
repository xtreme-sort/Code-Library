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
    int N;
    cin>>N;

    vector<int> tree[N];
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;

        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreesums(N,0);

    function<void(int,int)> compute = [&] (int v,int parent){
        subtreesums[v] += (v+1);
        for(auto child: tree[v]){
            if(child == parent) continue;
            compute(child,v);
            subtreesums[v] += subtreesums[child];
        }
    };


    compute(0,-1);
    for(int i=0;i<N;i++){
        cout<<subtreesums[i]<<endl;
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