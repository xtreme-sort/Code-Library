#include <bits/stdc++.h>

using namespace std;

int main(){
    
    auto find_rec_cycle = [&] (int x) -> int {
        int num = 0;

        if(x % 2 == 0 or x % 5 == 0) return num;
        map<int, int> mp;
        int rem = 1;
        while(mp.find(rem) == mp.end()){
            mp[rem] = num;
            rem = (rem * 10) % x;
            num++;
        }
        return num - mp[rem];
        
    };

    return 0;
}