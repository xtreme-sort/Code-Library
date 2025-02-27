// 90 degree rotation
// (i,j) -> (j,N-1-i) -> (N-1-i,N-1-j) -> (N-1-j,i)


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

    vector<vector<bool>> vis(N,vector<bool>(N,false));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vis[i][j]) continue;
            vis[i][j]=true;

            array<int,4> XC = {i,j,N-1-i,N-1-j}, YC ={j,N-1-i,N-1-j,i};
            vector<int> V;
            for(int d=0;d<4;d++){
                if(!vis[XC[d]][YC[d]]){
                    vis[XC[d]][YC[d]] = true;
                    V.push_back(grid[XC[d]][YC[d]]);
                }
            }

            //process V

        }
    }
}

