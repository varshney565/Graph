//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//optimization : two pointer
//tabulization : copy paste

class Solution
{
public:
    const int mod = 1e9+7;
    long long friend_pair(int n,vector<int>&dp){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        long long ans = 0;
        ans = (ans + friend_pair(n-1,dp))%mod;
        if(n-2 >= 0)
            ans = (ans + ((n-1)*friend_pair(n-2,dp))%mod)%mod;
        return dp[n] = ans;
    }

    long long friend_pair_tab(int N,vector<int>&dp){
        for(int n = 0 ; n <= N ; n++){
            if(n == 0){
                dp[n] = 1;
                continue;
            }
            long long ans = 0;
            ans = (ans + dp[n-1])%mod;
            if(n-2 >= 0)
                ans = (ans + ((n-1)*dp[n-2])%mod)%mod;
            dp[n] = ans;
        }
        return dp[N];
    }

    long long friend_pair_opti(int n){
        //1 1 2 4
        //0 1 2 3
        int a = 1;
        int b = 1;
        for(int i = 2 ; i <= n ; i++){
            int sum = b;
            sum += (i-1)*a;
            a = b;
            b = sum;
        }
        return b;
    }
    
    long long countFriendsPairings(int n) { 
        vector<int> dp(n+1,-1);
        return friend_pair(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends