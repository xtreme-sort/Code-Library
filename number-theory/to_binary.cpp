#include <bits/stdc++.h>
using namespace std;

#define int int64_t

string to_binary(int n){
    string s = "";
    while(n){
        s += (n%2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}


int main(){
    return 0;
}