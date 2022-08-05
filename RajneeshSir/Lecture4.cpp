//Given Four Directions and source and destination and a matrix find answer .... anything ...
//if there is a posibility of cycle in the matrix than i won't use DP
//if there is no posibility of cycle i can use DP.
#include<bits/stdc++.h>
using namespace std;
//Journey To The Moon
class dsu{
    public : 
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }
    
    int get(int i){
        if(p[i] == i)
            return i;
        return p[i] = get(p[i]);
    }
    
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2) 
            return false;
        p[p1] = p2;
        s[p2] += s[p1];
        s[p1] = 0;
        return true;
    }
};

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    dsu D(n);
    for(int i = 0 ; i < astronaut.size() ; i++){
        D.unite(astronaut[i][0],astronaut[i][1]);
    }
    int ans = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += D.s[i];
    }
    cout<<sum<<"\n";
    for(int j = 0 ; j < n ; j++){
        sum -= D.s[j];
        ans += sum*(D.s[j]);
    }
    return ans;
}

//Topological Sorting
//O(E+V)
void dfs(vector<vector<int>> &Graph,int src,vector<bool> &visited){
    visited[src] = true;
    for(int i = 0 ; i < Graph[src].size() ; i++){
        if(!visited[Graph[src][i]]){
            dfs(Graph,Graph[src][i],visited);
        }
    }
    cout<<src<<" ";
}

vector<int> topologicalSort(vector<vector<int>> &Graph){
    int n = Graph.size();
    vector<bool> visited(n,false);
    for(int i = 0 ; i < n ; i++){
        if(!visited[i])
            dfs(Graph,i,visited);
    }
}

//KahnsAlgo
void KahnsAlgo(int n,vector<vector<int>> &Graph){
    vector<int> In(n,0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < Graph[i].size() ; j++){
            //i---->Graph[i][j]
            In[Graph[i][j]]++;
        }
    }
    queue<int> PendingNodes;
    for(int i = 0 ; i < n ; i++){
        if(In[i] == 0){
            PendingNodes.push(i);
        }
    }
    
    vector<int> ans;
    while(!PendingNodes.empty()){
        int size = PendingNodes.size();
        while(size-->0){
            int Front = PendingNodes.front();
            PendingNodes.pop();
            ans.push_back(Front);
            for(int i = 0 ; i < Graph[Front].size() ; i++){
                In[Graph[Front][i]]--;
                if(In[Graph[Front][i]] == 0){
                    PendingNodes.push(Graph[Front][i]);
                }
            }
        }
    }
    if(ans.size() < n){
        cout<<"There is A Cycle in the Graph.";
        ans.clear();
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
//207 : Course Schedule
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> Graph(n,vector<int>());
    vector<int> Ind(n,0);
    for(int i = 0 ; i < prerequisites.size() ; i++){
        Graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        Ind[prerequisites[i][1]]++;
    }
    queue<int> JobsThatWillBeFinishedAtLast;
    for(int i = 0 ; i < Ind.size() ; i++){
        if(Ind[i] == 0){
            JobsThatWillBeFinishedAtLast.push(i);
        }
    }
    vector<int> ans;
    while(!JobsThatWillBeFinishedAtLast.empty()){
        int Front = JobsThatWillBeFinishedAtLast.front();
        ans.push_back(Front);
        JobsThatWillBeFinishedAtLast.pop();
        for(int i = 0 ; i < Graph[Front].size() ; i++){
            int v = Graph[Front][i];
            Ind[v]--;
            if(Ind[v] == 0){
                JobsThatWillBeFinishedAtLast.push(v);
            }
        }
    }
    if(ans.size() < n){
        return false;
    }
    return true;
}

//210
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> Graph(n,vector<int>());
    vector<int> Ind(n,0);
    for(int i = 0 ; i < prerequisites.size() ; i++){
        Graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        Ind[prerequisites[i][1]]++;
    }
    queue<int> JobsThatWillBeFinishedAtLast;
    for(int i = 0 ; i < Ind.size() ; i++){
        if(Ind[i] == 0){
            JobsThatWillBeFinishedAtLast.push(i);
        }
    }
    vector<int> ans;
    while(!JobsThatWillBeFinishedAtLast.empty()){
        int Front = JobsThatWillBeFinishedAtLast.front();
        ans.push_back(Front);
        JobsThatWillBeFinishedAtLast.pop();
        for(int i = 0 ; i < Graph[Front].size() ; i++){
            int v = Graph[Front][i];
            Ind[v]--;
            if(Ind[v] == 0){
                JobsThatWillBeFinishedAtLast.push(v);
            }
        }
    }
    if(ans.size() < n){
        ans.clear();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}