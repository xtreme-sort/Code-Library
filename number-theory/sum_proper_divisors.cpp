#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'


int32_t main() {

    auto d = [&](int x) -> int {
        int ans = 0;

        for(int i = 1 ; i*i <=x ; i++){
            if(x % i  == 0){
                if(i != x) ans += i;
                if(x/i != i and i != 1) ans += x/i;
            }
        }

        return ans;
    };
    
    return 0;
}