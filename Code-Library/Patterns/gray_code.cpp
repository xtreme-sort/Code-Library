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

    vector<string> V;
    V.push_back("0");
    V.push_back("1");

    for(int i=1;i<N;i++){
        vector<string> M = V;
        reverse(M.begin(),M.end());
        for(auto &x : V) x = "0" + x;
        for(auto &x : M) x = "1" + x;

        for(auto &x : M) V.push_back(x);
        M.clear();
    }

    for(auto x : V){
        cout<<x<<endl;
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