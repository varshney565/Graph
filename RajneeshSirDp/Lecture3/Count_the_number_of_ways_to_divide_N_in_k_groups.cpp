// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &dp){
    for(int i = 0 ; i < dp.size() ; i++) 
        cout<<dp[i]<<"  ";
    cout<<"\n";
}

void display(vector<vector<int>> &dp){
    int n = dp.size();
    int m = dp[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
 
//top down memoized
int go(int n,int k,vector<vector<int>> &dp){
    if(k == 1 || n == k){
        return dp[n][k] = 1;
    }
    if(dp[n][k] != -1) return dp[n][k];
    int SelfGroup = go(n-1,k-1,dp);
    int PartOfGroup = k*go(n-1,k,dp);
    return dp[n][k] = SelfGroup+PartOfGroup;
}

//bottom up tabulation
int go_tab(int N,int K,vector<vector<int>> &dp){
    for(int n = 1 ; n <= N ; n++){
        for(int k = 1 ; k <= K ; k++){
            if(k == 1 || n == k){
                dp[n][k] = 1;
                continue;
            }
            
            int SelfGroup = dp[n-1][k-1];
            int PartOfGroup = k*dp[n-1][k];
            dp[n][k] = SelfGroup+PartOfGroup;
        }
    }
    return dp[N][K];
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    int ans = go_tab(n,k,dp);
    display(dp);
    cout<<ans<<"\n";
}