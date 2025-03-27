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

class segment{
    private:    
        int N;
        vector<int> tree, inclazy, assignlazy;

    public:
        segment(int N_){
            N = 1;
            while(N < N_){
                N *= 2;
            }
            tree.assign(2*N, 0);
            inclazy.assign(2*N, 0);
            assignlazy.assign(2*N, 0);
        }

        void build(vector<int>& arr, int low, int high, int pos){
            if(low == high){
                tree[pos] = arr[low];
                return;
            }

            int mid = (low + high)/2;

            build(arr, low, mid, 2*pos + 1);
            build(arr, mid + 1, high, 2*pos + 2);

            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void build(vector<int>& arr){
            build(arr, 0, N-1, 0);
        }   
        
        void propagate(int low, int high, int pos){
            if(assignlazy[pos] != 0){
                tree[pos] = (high - low + 1) * assignlazy[pos];
                if(low != high){
                    assignlazy[2*pos + 1] = assignlazy[pos];
                    assignlazy[2*pos + 2] = assignlazy[pos];
                    inclazy[2*pos + 1] = 0;
                    inclazy[2*pos + 2] = 0;
                }
                assignlazy[pos] = 0;
            }

            if(inclazy[pos] != 0){
                tree[pos] += (high - low + 1) * inclazy[pos];
                if(low != high){
                    inclazy[2*pos + 1] += inclazy[pos];
                    inclazy[2*pos + 2] += inclazy[pos];
                }
                inclazy[pos] = 0;
            }
        }

        int sumquery(int ql, int qh, int low, int high, int pos){
            propagate(low, high, pos);
            if(ql <= low && qh >= high){
                return tree[pos];
            }
            if(qh < low || ql > high) return 0;
            
            int mid = (low + high) / 2;
        
            return sumquery(ql, qh, low, mid, 2*pos + 1) + sumquery(ql, qh, mid + 1, high, 2*pos +2);
        }

        int sumquery(int ql, int qh){
            return sumquery(ql, qh, 0, N-1, 0);
        }


        void updatelazy_rangeinc(int ql, int qh, int val, int low, int high, int pos){
            propagate(low, high, pos);
            if(ql <= low && qh >= high){
                inclazy[pos] += val;
                propagate(low, high, pos);
                return;
            }
            if(qh < low || ql > high) return;

            tree[pos] += (high - low + 1) * val;
            int mid = (low + high) / 2;
            updatelazy_rangeinc(ql, qh, val, low, mid, 2*pos + 1);
            updatelazy_rangeinc(ql, qh, val, mid + 1, high, 2*pos + 2);

            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void updatelazy_rangeinc(int ql, int qh, int val){
            updatelazy_rangeinc(ql, qh, val, 0, N-1, 0);
        }

        void updatelazy_rangeassign(int ql, int qh, int val, int low, int high, int pos){
            propagate(low, high, pos);
            if(ql <= low && qh >= high){
                assignlazy[pos] = val;
                propagate(low, high, pos);
                return; 
            }
            if(qh < low || ql > high) return;

            tree[pos] = (high - low + 1) * val;
            int mid = (low + high) / 2;
            updatelazy_rangeassign(ql, qh, val, low, mid, 2*pos + 1);
            updatelazy_rangeassign(ql, qh, val, mid + 1, high, 2*pos + 2);

            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void updatelazy_rangeassign(int ql, int qh, int val){
            updatelazy_rangeassign(ql, qh, val, 0, N-1, 0);
        }
};


void solve() {
    int N, Q;
    cin >> N >> Q;
 
    vector<int> A(N);
    array_input(A,N);
 
    segment seg(N);
    seg.build(A);
 
    while(Q--){
        int type;
        cin >> type;
 
        if(type == 1){
            int a, b, x;
            cin >> a >> b >> x;
            a--;
            b--;
            seg.updatelazy_rangeinc(a, b, x);
        }
        else if(type == 2){
            int a, b, x;
            cin >> a >> b >> x;
            a--;
            b--;
            seg.updatelazy_rangeassign(a, b, x);
        }
        else{
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << seg.sumquery(a, b) << endl;
        }

    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}