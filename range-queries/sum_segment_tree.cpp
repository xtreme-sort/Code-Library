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
            tree.assign(2*N , 0);
        }

        void build(vector<int>& arr, int low, int high, int pos){
            if(low == high){
                if(low < (int)arr.size()) tree[pos] = arr[low];
                return;
            }

            int mid = (low + high)/2;
            build(arr, low, mid, 2*pos + 1);
            build(arr, mid + 1, high, 2*pos + 2);
            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void build(vector<int>& arr){
            build(arr,0,N-1,0);
        }

        int sumquery(int ql, int qh, int low, int high, int pos){
            if(ql <= low && qh >= high) return tree[pos];
            if(qh < low || ql > high) return 0;

            int mid = (high + low) / 2;
            int sum = sumquery(ql, qh, low, mid, 2*pos + 1) + sumquery(ql, qh, mid + 1, high, 2*pos + 2);
            return sum;
        }

        int sumquery(int ql, int qh){
            return sumquery(ql, qh, 0, N-1, 0);
        }

        void update(int ind, int val, int low, int high, int pos){
            if(low == ind && high == ind){
                tree[pos] = val;
                return;
            }
            if(ind < low || ind > high) return;

            int mid = (low + high)/2;
            update(ind, val, low, mid, 2*pos + 1);
            update(ind, val, mid+1, high, 2*pos + 2);

            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void update(int ind, int val){
            update(ind, val, 0, N-1, 0);
        }

};


int32_t main(){
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    segment seg(arr.size());
    seg.build(arr);

    seg.update(2,4);
    cout << seg.sumquery(0, 3) << endl;
    return 0;
}