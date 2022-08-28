#include<bits/stdc++.h>
using namespace std;
//check directed Graph has Cycle Or Not????
//we have to check which node is part of the cycle
vector<int> isCycle(vector<vector<int>> &Graph){
    int n = Graph.size();
    vector<int> visited(n,0);
    function<void(int)> dfs = [&](int u){
        //mark the current node
        visited[u] = 1;
        //calling on all the unprocessed vertises
        bool isPartOfCycle = false;
        for(int i = 0 ; i < Graph[u].size() ; i++){
            int v = Graph[u][i];
            if(!visited[v]){
                dfs(v);
                if(visited[v] == -1){
                    isPartOfCycle = true;
                }
            }else if(visited[v] == 1 || visited[v] == -1){
                //cycle
                isPartOfCycle = true;
            }
        }
        visited[u] = 2;
        if(isPartOfCycle)
            visited[u] = -1;
     };
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}


//Disjoint Set Union
class dsu{
    public:
    vector<int> p;
    vector<int> rank;//help in the size of each connected component...
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        rank.resize(n,1);
    }

    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2) return false;
        p[p1] = p2; rank[p2] += rank[p1];return true;
    }
};

//684 : leetcode
class dsu{
    public : 
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    
    int get(int n){
        if(p[n] == n){
            return n;
        }
        return p[n] = get(p[n]);
    }
    
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p2] = p1;
        return true;
    }
};
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    dsu D(n+1);
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        bool a = D.unite(edges[i][0],edges[i][1]);
        if(!a){
            ans = edges[i];
            cout<<ans[0]<<" "<<ans[1]<<"\n";
        }
    }
    return ans;
}

// 1061
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
        if(p1 < p2){
            p[p2] = p1;
        }else{
            p[p1] = p2;
        }
        return true;
    }
};
string smallestEquivalentstring(string s1,string s2,string basestr){
    dsu D(26);
    for(int i = 0 ; i < s1.size() ; i++){
        D.unite(s1[i]-'a',s2[i]-'a');
    }
    string ans = "";
    for(int i = 0 ; i < basestr.size() ; i++){
        ans += D.get(basestr[i]-'a')+'a';
    }
    return ans;
}