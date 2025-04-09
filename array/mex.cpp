#include <bits/stdc++.h>

using namespace std;

template<typename T_vector>
void array_input(T_vector &v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}


int main(){
    int N;
    cin >> N;

    vector<int> V(N);
    array_input(V, N);

    auto MEX = [&](vector<int> V) -> int {
        sort(V.begin(), V.end());
        
        int mex = 0;
        for(int i = 0 ; i < N ; i++){
            if(V[i] == mex) mex++;
            else if(i > 0 and V[i] == V[i-1]) continue;
            else return i;
        }

        return mex;
    };

    cout<<MEX(V)<<endl;
    
    return 0;
}