#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){
                    if(s1[i] == s2[j]){
                        dp[i][j] = 1,ans = max(ans,1);
                    }
                }else{
                    if(s1[i] == s2[j]){
                        dp[i][j] = 1+dp[i-1][j-1],ans = max(ans,dp[i][j]);
                    }
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}