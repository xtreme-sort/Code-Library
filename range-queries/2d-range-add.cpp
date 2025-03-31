#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for(int i = 0 ; i < N ; i++){
        cin >> grid[i];
    }

    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));

    int Q;
    cin >> Q;

    while(Q--){
        int a, b;
        int c, d;
        int x;
        cin >> a >> b;
        cin >> c >> d;
        cin >> x;

        arr[a][b] += x;
        arr[c + 1][d + 1] += x;
        arr[a][d + 1] -= x;
        arr[c + 1][b] -= x;
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }



    return 0;
}