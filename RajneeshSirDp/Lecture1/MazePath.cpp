#include<bits/stdc++.h>
using namespace std;

/*
Steps :
1)Faith
2)Recursive tree
3)Recursive Code Memoization
4)Observation
5)Tabulation
6)Optimization
*/


void display(vector<int> &dp){
    for(int i = 0 ; i < dp.size() ; i++) 
        cout<<dp[i]<<" ";
    cout<<"\n";
}

void display(vector<vector<int>> &dp){
    int n = dp.size();
    int m = dp[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int dir[3][2] = {{-1,-1},{-1,0},{0,-1}};
int solve(int x,int y,vector<vector<int>>&dp){
    if(x == 0 && y == 0){
        return 1;
    }
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++){
        int newX = x+dir[i][0];
        int newY = y+dir[i][1];
        if(newX >= 0 && newY >= 0){
            ans += solve(newX,newY,dp);
        }
    }
    return dp[x][y] = ans;
}

int solve_tab(int X,int Y,vector<vector<int>>&dp){
    for(int x = 0 ; x <= X ; x++){
        for(int y = 0 ; y <= Y ; y++){
            if(x == 0 && y == 0){
                dp[x][y] = 1;
                continue;
            }
            
            int ans = 0;
            for(int i = 0 ; i < 3 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newY >= 0){
                    ans += dp[newX][newY];
                }
            }
            dp[x][y] = ans;
        }
    }
    return dp[X][Y];
}

int main(){
    //total number of ways to reach from (0,0) to (n-1,m-1)
    //moves available : (x,y) --> (x+1,y+1) , (x+1,y) , (x,y+1)
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<solve_tab(n-1,m-1,dp)<<"\n";
    return 0;
}