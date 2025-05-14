#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'


const int MOD = 1000000007;
const int inf = 1e18;
const int MAX_SIZE = 1e5 + 5;

void solve() {
    int N;
    cin >> N;

    vector<tuple<int,int,int>> A(N);

    for(int i = 0 ; i < N ; i++){
        cin >> get<0>(A[i]) >> get<1>(A[i]) >> get<2>(A[i]); 
    }

    sort(A.begin(), A.end(), [](auto x, auto y){
        return get<1>(x) < get<1>(y);
    });

    vector<int> st(N), en(N), c(N);

    for(int i = 0 ; i < N ; i++){
        st[i] = get<0>(A[i]);
        en[i] = get<1>(A[i]);
        c[i] = get<2>(A[i]);
    }

    vector<int> last_comaptible(N, -1);
    
    for(int i = 0 ; i < N ; i++){
        auto it = lower_bound(en.begin(), en.end(), st[i]);
        if(it == en.begin()) continue;
        it--;
        last_comaptible[i] = (it - en.begin());
    }

    vector<vector<int>> dp(N, vector<int>(2, -inf));

    dp[0][1] = c[0];
    dp[0][0] = 0;
    
    for(int i = 1 ; i < N ; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(last_comaptible[i] == -1) dp[i][1] = c[i];
        else dp[i][1] = max(dp[last_comaptible[i]][0], dp[last_comaptible[i]][1]) + c[i];
    }

    cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
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