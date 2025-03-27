#include <bits/stdc++.h>

using namespace std;

class union_find{
    private:
        vector<int> parent;
        vector<int> size;
        int components = 0;
    
    public:
        union_find(int n){
            if(n >= 0) 
            init(n);
        }

        void init(int n){
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            size.assign(n,1);
            components = n;
        }
        
        int find(int x){    
            if(x == parent[x]){
                return x;
            } 
            else{
                parent[x] = find(parent[x]);
                return parent[x];
            }
        }


        bool unite(int x, int y){
            x = find(x);
            y = find(y);

            if(x == y) return false;

            if(size[x] < size[y])
                swap(x,y);

            size[x] += size[y];
            parent[y] = x;
            components--;
            return true;
        }

        int num_components(){
            return components;
        }

};


int main(){
    

}