#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 20;
const int LOG = 31;
int basis[MAX_SIZE];


int insertVector(int num){
    for(int i = 0 ; i < LOG; i++){
        if(!(num & (1LL << i))) continue;
        
        if(!basis[i]){
            basis[i] = num;
            return;
        }

        num ^= basis[i];
    }
}

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0 ; i < N ; i++) cin >> A[i];

    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        ans += (basis[i] > 0);
    }
    
    cout << ans << endl;
}