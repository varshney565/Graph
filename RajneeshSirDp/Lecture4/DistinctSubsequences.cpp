#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct_tab(string s, string t) {
        vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,-1));
        const long long mod = INT_MAX+1;
        function<int(int,int)> go = [&](int N,int M){
            for(int n = 0 ; n <= N ; n++){
                for(int m = 0 ; m <= M ; m++){
                    if(m == 0){
                        dp[n][m] = 1LL;continue;
                    }
                    if(n == 0){
                        dp[n][m] = 0LL;continue;
                    }
                    
                    long long ans = 0;
                    if(s[n-1] == t[m-1]){
                        ans = ((long long)(dp[n-1][m-1]+dp[n-1][m]))%mod;
                    }else{
                        ans = dp[n-1][m];
                    }
                    dp[n][m] = ans;
                }
            }
            return dp[N][M];
        };
        return go(s.size(),t.size());
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(m == 0)
                return dp[n][m] = 1;
            if(n == 0)
                return dp[n][m] = 0;
            if(dp[n][m] != -1) return dp[n][m];
            int ans = 0;
            if(s[n-1] == t[m-1]){
                ans += go(n-1,m-1);
            }
            ans += go(n-1,m);
            return dp[n][m] = ans;
        };
        return go(s.size(),t.size());
    }
};