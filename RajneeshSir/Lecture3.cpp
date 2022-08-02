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
                /**
                 * we are passing vertices in the queue only when they are not visited and since we found
                 * the vertex which is at the top of the queue to be visited that means that there are already
                 * a path from source to that vertex,and we are reaching it again from differnt path,
                 * so that's why cycle is there.
                 * */
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

//Bipartite Graph
//SetA    SetB
//Bipartite means dividing the Graph in Two Sets such that there is no edge within elements of same set


//
//Note : if there is no cycle in graph : Graph is Bipartite

//NOTE : if cycle is there
//Odd Length Cycle in The Graph  ---> Graph is not Bipartite
//Even Length Cycle in The Graph ---> Graph is Bipartite


bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    queue<int> PendingNodes;
    int Colour = 1;
        for(int i = 0 ; i < n ; i++){
        if(!visited[i])
            PendingNodes.push(i);
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            while(size-->0){
                int Front = PendingNodes.front();
                PendingNodes.pop();
                if(visited[Front]){
                    if(visited[Front] != Colour) return false;
                    continue;
                }
                visited[Front] = Colour;
                for(int i = 0 ; i < graph[Front].size() ; i++){
                    if(!visited[graph[Front][i]])
                        PendingNodes.push(graph[Front][i]);
                }
            }
            Colour = 3 - Colour;
        }
    }
    return true;
}

//Leetcode 994
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> RottingOranges;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(grid[i][j] == 2)
                RottingOranges.push({i,j});
    int time = -1;
    if(RottingOranges.size() == 0) time++;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!RottingOranges.empty()){
        int size = RottingOranges.size();
        time++;
        while(size-->0){
            pair<int,int> FrontOrange = RottingOranges.front();
            RottingOranges.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newX = FrontOrange.first+dir[i][0];
                int newY = FrontOrange.second+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                    RottingOranges.push({newX,newY});
                    grid[newX][newY] = 2;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(grid[i][j] == 1) return -1;
    return time;
}

//Leetcode : 1020. Number of Enclaves
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    auto validate = [&](int x,int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    };
    
    queue<pair<int,int>> Cells;
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == 1){
            Cells.push({i,0});
            grid[i][0] = -1;
        }
        if(grid[i][m-1] == 1){
            Cells.push({i,m-1});
            grid[i][m-1] = -1;
        }
    }
    for(int j = 1 ; j < m - 1 ; j++){
        if(grid[0][j] == 1){
            Cells.push({0,j});
            grid[0][j] = -1;
        }
        if(grid[n-1][j] == 1){
            Cells.push({n-1,j});
            grid[n-1][j] = -1;
        }
    }
    while(!Cells.empty()){
        int size = Cells.size();
        while(size-->0){
            pair<int,int> Front = Cells.front();
            Cells.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newX = Front.first+dir[i][0];
                int newY = Front.second+dir[i][1];
                if(validate(newX,newY) && grid[newX][newY] == 1){
                    Cells.push({newX,newY});
                    grid[newX][newY] = -1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(grid[i][j] == 1)
                ans++;
    return ans;
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