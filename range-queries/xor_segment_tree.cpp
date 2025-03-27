#include <bits/stdc++.h> 

using namespace std;

#define int int64_t

class segment{
    private:
        int N;
        vector<int> tree;
    public:
        segment(int N_){
            N = 1;
            while(N < N_) N *= 2;
            tree.assign(2*N, 0);
        }

        void build(vector<int>& arr, int low, int high, int pos){
            if(low == high){
                if(low < (int) arr.size()) tree[pos] = arr[low];
                return;
            }

            int mid = (low + high)/2;
            build(arr, low, mid, 2*pos + 1);
            build(arr, mid + 1, high, 2*pos + 2);
            
            tree[pos] = tree[2*pos + 1]^tree[2*pos + 2];
        }

        void build(vector<int>& arr){
            build(arr, 0, N-1, 0);
        }

        int xorquery(int ql, int qh, int low, int high, int pos){
            if(ql <= low && qh >= high) return tree[pos];
            if(qh < low || ql > high) return INT64_C(0);

            int mid = (low + high)/2;
            
            int xor_ = xorquery(ql, qh, low, mid, 2*pos + 1)^xorquery(ql, qh, mid + 1, high, 2*pos + 2);
            return xor_;
        }

        int xorquery(int ql, int qh){
            return xorquery(ql, qh, 0, N-1, 0);
        }

        void update(int ind, int val, int low, int high, int pos){
            if(low == ind && high == ind){
                tree[pos] = val;
                return;
            }
            if(ind < low || ind > high) return;

            int mid = (low + high)/2;
            update(ind, val, low, mid, 2*pos + 1);
            update(ind, val, mid + 1, high, 2*pos + 2);
            tree[pos] = tree[2*pos + 1]^tree[2*pos + 2];
        }

        void update(int ind, int val){
            update(ind, val, 0, N-1, 0);
        }
};



int32_t main(){
    int N,Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0 ; i < N ; i++) cin >> A[i];

    segment seg(N);
    seg.build(A);

    while(Q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cout << seg.xorquery(a,b) << endl;
    }
    return 0;
}