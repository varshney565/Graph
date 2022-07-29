#include<iostream>
#include<vector>
#include<functional>
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



//Lecture 2 : 


//Q1 : Get Connected Components
//Complexity : O(V+E)
void dfs(vector<vector<pair<int,int>>> &adj,int src,vector<bool> &visited){
    visited[src] = true;
    for(int i = 0 ; i < adj[src].size() ; i++){
        pair<int,int> Edge = adj[src][i];
        if(!visited[Edge.first]){
            dfs(adj,Edge.first,visited);
        }
    }
}

int GetConnectedComponents(vector<vector<pair<int,int>>> &adj){
    vector<bool> visited(adj.size(),false);
    int totalNumberOfComponents = 0;
    for(int i = 0 ; i < adj.size() ; i++){
        if(!visited[i]){
            dfs(adj,i,visited);
            totalNumberOfComponents++;
        }
    }
    return totalNumberOfComponents;
}

//Q2 : Leetcode 200
 int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    auto isValid = [&](int i,int j){
        if(i >= 0 && i < n && j >= 0 && j < m){
            return true;
        }
        return false;
    };
    
    function<void(int,int)> dfs = [&](int x,int y){
        //mark
        grid[x][y] = '0';
        //dfs call on all unvisited vertices
        for(int i = 0 ; i < 4 ; i++){
            int dirx = dir[i][0];
            int diry = dir[i][1];
            int newX = x+dirx;
            int newY = y+diry;
            if(isValid(newX,newY) && grid[newX][newY] == '1'){
                dfs(newX,newY);
            }
        }
    };
    
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == '1'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}


//Q3 : Leetcode 695
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    
    auto isValid = [&](int x,int y){
        if(x >= 0 && x < n && y >= 0 && y < m){
            return true;
        }
        return false;
    };
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int temp = 0;
    function<void(int,int)> dfs = [&](int x,int y){
        //mark
        grid[x][y] = 0;
        temp++;
        //call on all unvisited vertices
        for(int i = 0 ; i < 4 ; i++){
            int newX = x+dir[i][0];
            int newY = y+dir[i][1];
            if(isValid(newX,newY) && grid[newX][newY] == 1){
                dfs(newX,newY);
            }
        }
    };
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1){
                temp = 0;
                dfs(i,j);
                ans = max(ans,temp);
            }
        }
    }
    return ans;
}

//Q4 : Leetcode 463
int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    auto isValid = [&](int i,int j){
        if(i >= 0 && i < n && j >= 0 && j < m){
            return true;
        }
        return false;
    };
    
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 0)
                continue;
            if(!isValid(i-1,j) || grid[i-1][j] == 0) ans++;
            if(!isValid(i+1,j) || grid[i+1][j] == 0) ans++;
            if(!isValid(i,j-1) || grid[i][j-1] == 0) ans++;
            if(!isValid(i,j+1) || grid[i][j+1] == 0) ans++;
        }
    }
    return ans;
}

//Q5 : Leetcode 130
void solve(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    
    //DFS call
    function<void(int,int)> dfs = [&](int x,int y){
        //mark
        grid[x][y] = 'T';
        //visit all unvisited neighbours who has 'O' at its place.
        for(int i = 0 ; i < 4 ; i++){
            int newX = x+dir[i][0];
            int newY = y+dir[i][1];
            if(newX >=0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 'O'){
                dfs(newX,newY);
            }
        }
    };
    
    //dfs call on boundries with 'O'
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == 'O') dfs(i,0);
        if(grid[i][m-1] == 'O') dfs(i,m-1);
    }
    
    for(int j = 0 ; j < m ; j++){
        if(grid[0][j] == 'O') dfs(0,j);
        if(grid[n-1][j] == 'O') dfs(n-1,j);
    }
    
    
    //Final Ans Call
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }else if(grid[i][j] == 'T'){
                grid[i][j] = 'O';
            }
        }
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
    cout<<GetConnectedComponents(adj)<<"\n";
    return 0;
}




/**
 * 
 * 
 * 
*/