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
 
 
class Node{
    public:
        int sum, prefix, suffix, MSS;
 
        Node() {}
 
        Node(int val){
            sum = prefix = suffix = MSS = val;
        }
};
 
 
class segment{
    private:
        int N;
        vector<Node> tree;
    public:
        segment(int N_){
            N = 1;
            while(N < N_) N *= 2;
            tree.assign(2*N , 0);
        }
 
        Node merge(Node& left, Node& right){
            Node res;
            res.sum = left.sum + right.sum;
            res.prefix = max(left.prefix, left.sum + right.prefix);
            res.suffix = max(left.suffix + right.sum, right.suffix);
            res.MSS = max({left.suffix + right.prefix, left.MSS, right.MSS});
            return res;
        }
 
        void build(vector<int>& arr, int low, int high, int pos){
            if(low == high){
                if(low < (int)arr.size()) tree[pos] = Node(arr[low]);
                return;
            }
 
            int mid = (low + high)/2;
            build(arr, low, mid, 2*pos + 1);
            build(arr, mid + 1, high, 2*pos + 2);
            tree[pos] = merge(tree[2*pos + 1], tree[2*pos + 2]);
        }
 
        void build(vector<int>& arr){
            build(arr, 0, N-1, 0);
        }
 
        Node maxquery(int ql, int qh, int low, int high, int pos){
            if(ql <= low && qh >= high) return tree[pos];
            if(qh < low || ql > high) return 0;
 
            int mid = (high + low) / 2;
            Node left = maxquery(ql, qh, low, mid, 2*pos + 1);
            Node right = maxquery(ql, qh, mid + 1, high, 2*pos + 2);
            Node res = merge(left, right);
            return res;
        }
 
        Node maxquery(int ql, int qh){
            return maxquery(ql, qh, 0, N-1, 0);
        }
 
        void update(int ind, int val, int low, int high, int pos){
            if(low == ind && high == ind){
                tree[pos] = Node(val);
                return;
            }
            if(ind < low || ind > high) return;
 
            int mid = (low + high)/2;
            update(ind, val, low, mid, 2*pos + 1);
            update(ind, val, mid+1, high, 2*pos + 2);
 
            tree[pos] = merge(tree[2*pos + 1], tree[2*pos + 2]);
        }
 
        void update(int ind, int val){
            update(ind, val, 0, N-1, 0);
        }
 
};
 
 
 
 
void solve() {
    int N,Q;
    cin >> N >> Q;
 
    vector<int> A(N);
    array_input(A,N);
 
    segment seg(N);
    seg.build(A);
 
    while(Q--){
        int k, u;
        cin >> k >> u;
        k--;
        seg.update(k, u);
        int ans = seg.maxquery(0,N-1).MSS;
        if(ans > 0) cout << ans << endl;
        else cout << 0 << endl;
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