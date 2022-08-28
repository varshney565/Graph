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
//Fibonacci Number

int fib(int n,vector<int> &dp){
    if(dp[n] != -1)
        return dp[n];
    if(n <= 1){
        return dp[n] = n;
    }
    return dp[n] = fib(n-1,dp)+fib(n-2,dp);
};

int fib_tab(int N,vector<int> &dp){
    for(int n = 0 ; n <= N ; n++){
        if(n <= 1){
            dp[n] = n;
            continue;
        }
        dp[n] = dp[n-1]+dp[n-2];
    }
    return dp[N];
};

int fib_opti(int n){
    int a = 0;
    int b = 1;
    for(int i = 2 ; i <= n ; i++){
        int sum = a+b;
        a = b;
        b = sum;
    }
    return b;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int ans = fib_tab(n,dp);
    cout<<ans<<"\n";
    return 0;
}