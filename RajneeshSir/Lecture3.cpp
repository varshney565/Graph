#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include<set>
#include<queue>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &adj,int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void display(vector<vector<pair<int,int>>> &adj,int V){
    for(int u = 0 ; u < V ; u++){
        cout<<u<<" --> ";
        for(auto v : adj[u]){
            cout<<"(";
            cout<<v.first<<","<<v.second;
            cout<<") ";
        }
        cout<<"\n";
    }
}

//Lecture 3 : 

//Q1 : Leetcode 694 or LintCode 860
void dfs(vector<vector<int>> &grid,vector<vector<int>> &dir,int x,int y,string &call){
    int n = grid.size();
    int m = grid[0].size();
    grid[x][y] = 0;
    for(int i = 0 ; i < 4 ; i++){
        int newX = x+dir[i][0];
        int newY = y+dir[i][1];
        if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1){
            call += to_string(i);
            dfs(grid,dir,newX,newY,call);
        }
    }
    call += "b";
}

int numberofDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    set<string> Record;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1){
                string call = "";
                dfs(grid,dir,i,j,call);
                if(Record.find(call) == Record.end()){
                    Record.insert(call);
                }
            }
        }
    }
    return Record.size();
}


//Q2 : BFS
//cycle k basis p kuch kam krna h to ye wala BFS
//In this case The Maximum size of queue will be O(E)
void BFS(vector<vector<int>> &Graph,int src){
    queue<int> PendingNodes;
    PendingNodes.push(src);
    vector<int> visited(Graph.size(),false);
    PendingNodes.push(src);
    int level = 0;
    while(!PendingNodes.empty()){
        int size = PendingNodes.size();
        cout<<"Level : "<<level<<"--->";
        while(size-->0){
            int Front = PendingNodes.front();
            PendingNodes.pop();
            if(!visited[Front]){
                cout<<" "<<Front;
                visited[Front] = true;
                for(int i = 0 ; i < Graph[Front].size() ; i++){
                    int v = Graph[Front][i];
                    if(!visited[v]){
                        PendingNodes.push(v);
                    }
                }
            }else{
                //cycle is there
            }
        }
        cout<<"\n";
        level++;
    }
}

//cycle se koi matlab nhi h
//In this case maximum size of queue will be O(V)
void BFS_without_cycle(vector<vector<int>> &Graph,int src){
    queue<int> PendingNodes;
    PendingNodes.push(src);
    vector<int> visited(Graph.size(),false);
    PendingNodes.push(src);
    visited[src] = true;

    int level = 0;
    while(!PendingNodes.empty()){
        int size = PendingNodes.size();
        cout<<"Level : "<<level<<"--->";
        while(size-->0){
            int Front = PendingNodes.front();
            PendingNodes.pop();
            cout<<" "<<Front;
            visited[Front] = true;
            for(int i = 0 ; i < Graph[Front].size() ; i++){
                int v = Graph[Front][i];
                if(!visited[v]){
                    PendingNodes.push(v);
                    visited[v] = true;
                }
            }
        }
        cout<<"\n";
        level++;
    }
}

int main(){
    int V = 9;
    vector<vector<pair<int,int>>> adj(V);
    addEdge(adj,0,1,10);
    addEdge(adj,0,3,10);
    addEdge(adj,2,1,10);
    addEdge(adj,3,2,40);
    addEdge(adj,2,7,2);
    addEdge(adj,2,8,4);
    addEdge(adj,7,8,3);
    addEdge(adj,3,4,2);
    addEdge(adj,4,5,2);
    addEdge(adj,5,6,3);
    addEdge(adj,4,6,8); 
    return 0;
}




/**
 * 
 * 
 * 
*/