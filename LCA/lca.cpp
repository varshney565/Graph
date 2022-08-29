#include<bits/stdc++.h>
using namespace std;

//Given Graph is tree
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    //assuming 0 i the root,if not root will be the one whose indegree is 0
    //InComplete Will Do it : date : 3 Sep 2022
    // dfs(0,-1);
}