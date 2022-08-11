#include<bits/stdc++.h>
using namespace std;

//Krushkal Algo
class dsu{
    public: 
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};
vector<vector<int>> Krushkal(vector<vector<int>> &Edges){
    sort(Edges.begin(),Edges.end(),[](const vector<int>& a,const vector<int>&b){
        return a[2] < b[2];
    });
    int n = Edges.size();
    dsu D(n);
    
}