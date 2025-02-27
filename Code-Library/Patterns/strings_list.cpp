#include <bits/stdc++.h>
using namespace std;



int main(){
    string S;
    cin>>S;


    auto MEX = [&] (string S)->string {
        vector<string> strings = {""};

        while(true){
            vector<string> temp;
            for(auto x : strings){
                for(int i=0;i<26;i++){
                    string str = x + char('a'+i);
                    if(S.find(str)==string::npos){
                        return str;
                    }
                    temp.push_back(str);
                }
            }
            strings.swap(temp);
        }
    };

    cout<<MEX(S)<<endl;
}

