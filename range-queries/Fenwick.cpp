#include <bits/stdc++.h>

using namespace std;

#define int int64_t


// 1 - indexing 
class FenwickTree{
    private:
        int N;
        vector<int> tree;

    public:
        FenwickTree(int N_){
            N = N_ + 1;
            tree.assign(N, 0);
        }

        int rsq(int a){
            if(a >= N) return -1;
            int tot = 0;
            while(a >= 1){
                tot += tree[a];
                a -= a&-a;
            }

            return tot;
        }

        int rsq(int a, int b){
            return rsq(b) - rsq(a - 1);
        }

        void update(int k, int x){
            while(k < N){
                tree[k] += x;
                k += k&-k;
            }
        }

        void build(vector<int> &V){
            for(int i = 1 ; i <= V.size() ; i++){
                this->update(i , V[i - 1]);
            }
        }

        void print(){
            for(auto x : tree){
                cout << x << " ";
            }
            cout << endl;
        }

};

int32_t main(){ 
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0 ; i < N ; i++) cin >> A[i];

    FenwickTree tree(N);
    tree.build(A);



    return 0;
}