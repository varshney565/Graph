//LintCOde 788
//The maze II Leetcode Premium
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<vector<int>>> Cal(n,vector<vector<int>>(m,vector<int>(4,-1)));
        //Left
        for(int i = 0 ; i < n ; i++){
            int val = i*m;
            for(int j = 0 ; j < m ; j++){
                if(maze[i][j] == 1){
                    val = i*m+j+1;
                    continue;
                }
                Cal[i][j][0] = val;
            }
        }
        //Right
        for(int i = 0 ; i < n ; i++){
            int val = i*m+m-1;
            for(int j = m-1 ; j >= 0 ; j--){
                if(maze[i][j] == 1){
                    val = i*m+j-1;
                    continue;
                }
                Cal[i][j][1] = val;
            }
        }
        //Down
        for(int j = 0 ; j < m ; j++){
            int val = j;
            for(int i = 0 ; i < n ; i++){
                if(maze[i][j] == 1){
                    val = i*m+j+m;
                    continue;
                }
                Cal[i][j][3] = val;
            }
        }
        //Top
        for(int j = 0 ; j < m ; j++){
            int val = (n-1)*m+j;
            for(int i = n-1 ; i >= 0 ; i--){
                if(maze[i][j] == 1){
                    val = i*m+j-m;
                    continue;
                }
                Cal[i][j][2] = val;
            }
        }
        //0 index : <-----
        //1 index : ----->
        //2 index : top to down
        //3 index : down to top
        set<pair<int,int>> PendingCells;
        vector<bool> visited(n*m,false);
        int dest = destination[0]*m+destination[1];
        PendingCells.insert({0,start[0]*m+start[1]});
        while(!PendingCells.empty()){
            auto front = *PendingCells.begin();
            PendingCells.erase(front);
            int x = front.second/m;
            int y = front.second%m;
            int dist = front.first;
            if(visited[front.second])
                continue;
            visited[front.second] = true;
            cout<<x<<" "<<y<<" "<<dist<<"\n";
            if(front.second == dest)
                return dist;
            for(int i = 0 ; i < 4 ; i++){
                int cell = Cal[x][y][i];
                int newX = cell/m;
                int newY = cell%m;
                if(!visited[cell]){
                    PendingCells.insert({dist+abs(newX-x)+abs(newY-y),cell});
                }
            }
        }
        return -1;
    }
};


//Leetcode 499
//the one which is coming lexiographicaly smaller will come first
//The Maze I
//The Maze II
//The Maze III