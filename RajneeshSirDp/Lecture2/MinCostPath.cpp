// https://www.geeksforgeeks.org/min-cost-path-dp-6/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MinCostPath(int n, int m, vector<vector<int>> M){
        int dir[3][2] = {{0,-1},{-1,-1},{-1,0}};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(x == 0 && y == 0)
                return M[x][y];
            if(dp[x][y] != -1)
                return dp[x][y];
            int ans = M[x][y];
            int t = INT_MAX;
            for(int i = 0 ; i < 3 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    t = min(t,go(newX,newY));
                }
            }
            return dp[x][y] = ans+t;
        };
        return go(n-1,m-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.MinCostPath(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends