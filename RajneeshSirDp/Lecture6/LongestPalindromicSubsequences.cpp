//BackEngine
//Longest Palindromic Substring Path
#include<bits/stdc++.h>
using namespace std;

string BackEngine(string &str,vector<vector<int>>&dp,int s,int e){
    if(s > e)
        return "";
    if(s == e){
        return str.substr(s,1);
    }
    if(str[s] == str[e]){
        return str[s]+BackEngine(str,dp,s+1,e-1)+str[e];
    }else if(dp[s+1][e] > dp[s][e-1]){
        return BackEngine(str,dp,s+1,e);
    }else{
        return BackEngine(str,dp,s,e-1);
    }
}

string longestPalindromeSubsequence(string str) {
    int n = str.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    auto lpss = [&](){
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    dp[i][j] = 1;
                }else if(gap == 2){
                    dp[i][j] = ((str[i] == str[j])?2:max(dp[i+1][j],dp[i][j-1]));
                }else{
                    dp[i][j] = ((str[i] == str[j])?2+dp[i+1][j-1]:max(dp[i+1][j],dp[i][j-1]));
                }
                i++;
                j++;
            }
        }
    };
    lpss();
    return BackEngine(str,dp,0,n-1);
}


int main(){
    string s;
    cin>>s;
    cout<<longestPalindromeSubsequence(s)<<"\n";
}