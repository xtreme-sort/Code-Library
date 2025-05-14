#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
 
    vector<string> grid(N);
 
    for(auto &x : grid){
        cin >> x;
    }
    
    // 0 - indexing
    // first fill in the rows => prefix[i][j + 1] = prefix[i][j] + grid[i][j] == '*'
    // push these to columns => prefix[i + 1][j] = prefix[i][j]
    
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            prefix[i + 1][j + 1] = prefix[i + 1][j];
            prefix[i + 1][j + 1] += (grid[i][j] == '*');
        }
    }
 
    for(int j = 0 ; j < N ; j++){
        for(int i = 0 ; i < N ; i++){
            prefix[i + 1][j + 1] += prefix[i][j + 1];
        }
    }    
 
    while(Q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        cout << prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1] << endl; 
    }
}