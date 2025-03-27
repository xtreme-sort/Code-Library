#include <bits/stdc++.h>

using namespace std;


int main(){
    int N;
    cin>>N;

    vector<vector<int>> grid(N,vector<int>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> diag1(2*N-1),diag2(2*N-1);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            diag1[i+j].push_back(grid[i][j]);
            diag2[i-j+N-1].push_back(grid[i][j]);
        }
    }

    // process diagnols
}