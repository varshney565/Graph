#include<bits/stdc++.h>
using namespace std;

class dsu{
  public:
    vector<int> p;
    vector<int> s;
    vector<int> cnt;
    dsu(int n,vector<int>&initial){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
        cnt.resize(n,0);
        for(int i = 0 ; i < initial.size() ; i++){
            cnt[initial[i]]++;
        }
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
        if(cnt[p2]){
            p[p1] = p2;
            s[p2] += s[p1];
            cnt[p2] += cnt[p1];
        }else{
            p[p2] = p1;
            s[p1] += s[p2];
            cnt[p1] += cnt[p2];
        }
        return true;
    }
};


class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {        
        int n = graph.size();
        sort(initial.begin(),initial.end());
        dsu d(n,initial);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(graph[i][j] == 1)
                    d.unite(i,j);
            }
        }
        int ans = -1;
        int max_ = 0;
        for(int i = 0 ; i < n ; i++){
            if(d.p[i] == i && d.cnt[i] == 1 && max_ < d.s[i]){
                max_ = d.s[i];
                ans = i;
            }
        }
        if(ans == -1) return initial[0];
        return ans;
    }
};