//Given a dice and an integer n
//means we can take jump of 1,2,3,4,5,6
//find the number of ways to reach n


#include<bits/stdc++.h>
using namespace std;

int findWays(int n,vector<int> &dp){
    if(n == 0)
        return dp[n] = 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i = 1 ; i <= 6; i++){
        if(n-i >= 0)
            ans += findWays(n-i,dp);
    }
    return dp[n] = ans;
}

int findWays_tab(int N,vector<int>&dp){
    for(int n = 0 ; n <= N ; n++){
        if(n == 0){
            dp[n] = 1;
            continue;
        }
        int ans = 0;
        for(int i = 1 ; i <= 6; i++){
            if(n-i >= 0)
                ans += dp[n-i];
        }
        dp[n] = ans;
    }
    return dp[N];
}

int findWaysOpti(int N){
    vector<int> dp(N+1,-1);
    for(int n = 0 ; n <= N ; n++){
        if(n == 0){
            dp[n] = 1;
            continue;
        }
        int ans = 0;
        dp[n] = 2*dp[n-1];
        if(n-1-6 >= 0)
            dp[n] -= dp[n-7];
    }
    return dp[N];
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<findWays(n,dp)<<"\n";
    return 0;
}
