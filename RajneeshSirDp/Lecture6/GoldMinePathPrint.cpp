//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int dir[3][2] = {{0,1},{-1,1},{1,1}};
void print_path(vector<vector<int>> &dp,int x,int y,int &n,int &m){
    if(y == m-1){
        cout<<"("<<x<<","<<y<<")";
        return;
    }
    int nX=-1,nY=-1;
    int data = 0;
    for(int i = 0 ; i < 3 ; i++){
        int newX = x+dir[i][0];
        int newY = y+dir[i][1];
        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
            if(data < dp[newX][newY]){
                nX = newX;
                nY = newY;
                data = dp[newX][newY];
            }
        }
    }
    cout<<"("<<x<<","<<y<<") --> ";
    print_path(dp,nX,nY,n,m);
}

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(dp[x][y] != -1)
                return dp[x][y];
            int ans = M[x][y];
            int t = 0;
            for(int i = 0 ; i < 3 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0  && newY < m){
                    t = max(t,go(newX,newY));
                }
            }
            return dp[x][y] = ans+t;
        };
        int ans = 0;
        int si = 0;
        for(int i = 0 ; i < n ; i++){
            int res = go(i,0);
            if(res > ans){
                ans = res;
                si = i;
            }
        }
        print_path(dp,si,0,n,m);
        cout<<"\n";
        return ans;
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
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends