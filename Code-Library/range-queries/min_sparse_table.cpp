#include <bits/stdc++.h>

using namespace std;

#define int int64_t

class sparse{
    private:
        int N;
        vector<vector<int>> table;

    public:
        sparse(int N_){
            N = N_;
            int max_log = log2(N) + 1;
            table.assign(max_log, vector<int>(N));
        }

        void build(vector<int>& arr){
            for (int i = 0 ; i < N ; i++) {
                table[0][i] = arr[i];
            }

            for(int row = 1 ; row < (int)table.size() ; row++){
                for(int i = 0 ; i + (1<<row) <= N ; i++){
                    table[row][i] = min(table[row-1][i], table[row-1][i + (1<<(row-1))]);
                }
            }
        }

        int minquery(int a, int b){
            int len = log2(b - a + 1);
            return min(table[len][a], table[len][b - (1<<len) + 1]);
        }

};


int32_t main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &x : A){
        cin >> x;
    }  

    sparse table(N);
    table.build(A);

    cout << table.minquery(0, 2) << endl;
    return 0;
}