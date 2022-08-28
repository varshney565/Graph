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

//Leetcode 959
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

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = m+1;
        dsu d(n*n);
        for(int i = 0 ; i < n ; i++){
            d.unite(0,i);
            d.unite((n-1)*n+i,0);
            d.unite(i*n,0);
            d.unite(i*n+n-1,0);
        }
        int ans = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '/'){
                    if(!d.unite(i*n+j+1,(i+1)*n+j))
                        ans++;
                }else if(grid[i][j] == '\\'){
                    if(!d.unite(i*n+j,(i+1)*n+j+1))
                        ans++;
                }
            }
        }
        return ans;
    }
};

//Leetcode 990
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
        if(p1 == p2) return false;
        p[p1] = p2;
        return true;
    }
};

void MySort(vector<string> &equations){
    int n = equations.size();
    int i = 0;
    int j = n-1;
    while(i < j){
        while(i <= j && (equations[i][1] == '=')){
            i++;
        }
        while(j >= i && (equations[j][1] == '!')){
            j--;
        }
        if(i < j){
            swap(equations[i],equations[j]);
            i++;
            j--;
        }
    }
}

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        MySort(equations);
        dsu d(26);
        for(int i = 0 ; i < n ; i++){
            if(equations[i][1] == '='){
                d.unite(equations[i][0]-'a',equations[i][3]-'a');
            }else{
                int p1 = d.get(equations[i][0]-'a');
                int p2 = d.get(equations[i][3]-'a');
                if(p1 == p2) return false;
            }
        }
        return true;
    }
};

//Leetcode 815 : Buus Routes
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        queue<int> PendingBusStops;
        map<int,set<int>> Buses;
        for(int i = 0 ; i < routes.size() ; i++){
            for(int j = 0 ; j < routes[i].size() ; j++){
                Buses[routes[i][j]].insert(i);
            }
        }
        vector<bool> visited(routes.size(),false);
        PendingBusStops.push(source);
        int TotalNumberOfBuses = 0;
        while(!PendingBusStops.empty()){
            int size = PendingBusStops.size();
            while(size-->0){
                int CurrentStop = PendingBusStops.front();
                if(CurrentStop == target)
                    return TotalNumberOfBuses;
                PendingBusStops.pop();
                while(Buses[CurrentStop].size() > 0){
                    int index = *Buses[CurrentStop].begin();
                    Buses[CurrentStop].erase(index);
                    if(visited[index])
                        continue;
                    for(int i = 0 ; i < routes[index].size() ; i++){
                        PendingBusStops.push(routes[index][i]);
                    }
                    visited[index] = true;
                }
            }
            TotalNumberOfBuses++;
        }
        return -1;
    }
};


//Dijkrashta
void Dj(vector<vector<pair<int,int>>> &graph,int source){
    set<vector<int>> PendingNodes;
    int n = graph.size();
    PendingNodes.insert({0,source,-1,0});
    vector<bool> visited(n,false);
    while(!PendingNodes.empty()){
        vector<int> Front = *PendingNodes.begin();
        PendingNodes.erase(Front);
        if(visited[Front[1]])
            continue;
        visited[Front[1]] = true;
        for(int i = 0 ; i < graph[Front[1]].size() ; i++){
            int w = graph[Front[1]][i].second;
            int v = graph[Front[1]][i].first;
            if(!visited[v]){
                PendingNodes.insert({Front[0]+w,v,Front[1],w});
            }
        }
    }
    //Done
}

//Prisms algo --> used for MST
//just sort the edges on the basis of Edge Weight and done 