#include <bits/stdc++.h>

using namespace std;

#define int int64_t

class segment{
    private:
        int N;
        vector<int> tree,lazy;
    public:
        segment(int N_){
            N = 1;
            while(N < N_) N *= 2;
            tree.assign(2*N, 0);
            lazy.assign(2*N, 0);
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

        void propagate(int low, int high, int pos) {
            if (lazy[pos] != 0) {
                tree[pos] += (high - low + 1) * lazy[pos];
                if (low != high) {
                    lazy[2 * pos + 1] += lazy[pos]; 
                    lazy[2 * pos + 2] += lazy[pos];
                }
                lazy[pos] = 0;
            }
        }

        int sumquery(int ql, int qh, int low, int high, int pos){
            propagate(low, high, pos);
            if(ql <= low && qh >= high) return tree[pos];
            if(qh < low || ql > high) return 0;

            int mid = (high + low) / 2;
            int sum = sumquery(ql, qh, low, mid, 2*pos + 1) + sumquery(ql, qh, mid + 1, high, 2*pos + 2);
            return sum;
        }

        int sumquery(int ql, int qh){
            return sumquery(ql, qh, 0, N-1, 0);
        }

        void update(int ql, int qh, int val, int low, int high, int pos){
            if(ql <= low && qh >= high){
                tree[pos] = val;
                return;
            }
            if(qh < low || ql > high) return;

            int mid = (low + high)/2;
            update(low, qh, val, low, mid, 2*pos + 1);
            update(ql, qh, val, mid+1, high, 2*pos + 2);

            tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
        }

        void update(int ql, int qh, int val){
            update(ql, qh, val, 0, N-1, 0);
        }

        void updatelazy(int ql, int qh, int val, int low, int high, int pos) {
            propagate(low, high, pos);
            
            if (ql > high || qh < low) return;
        
            if (ql <= low && qh >= high) {
                tree[pos] += (high - low + 1) * val;
                if (low != high) {
                    lazy[2 * pos + 1] += val;
                    lazy[2 * pos + 2] += val;
                }
                return;
            }
        
        
            int mid = (low + high) / 2;
            updatelazy(ql, qh, val, low, mid, 2 * pos + 1);
            updatelazy(ql, qh, val, mid + 1, high, 2 * pos + 2);
        
            tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
        }
        

        void updatelazy(int ql, int qh, int val){
            updatelazy(ql, qh, val, 0, N-1, 0);
        }

};


int32_t main(){
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    segment seg(arr.size());
    seg.build(arr);

    seg.update(0,2,4);
    cout << seg.sumquery(0, 0) << endl;
    return 0;
}