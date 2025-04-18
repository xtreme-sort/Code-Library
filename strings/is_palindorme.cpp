#include <bits/stdc++.h>

using namespace std;

int main(){
    auto is_palidrome = [&](string s) -> bool {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    };
    return 0;
}