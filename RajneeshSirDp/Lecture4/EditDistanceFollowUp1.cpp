#include<bits/stdc++.h>
using namespace std;
//insert  --> a
//delete  --> b
//replace --> c
int minDistance(string s1, string s2,int a,int b,int c) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    function<int(int,int)> go = [&](int n,int m){
        if(n == 0 || m == 0){
            if(!n) return dp[n][m] = a*m;
            if(!m) return dp[n][m] = b*n;
            else return dp[n][m] = 0;
        }

        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]){
            int ans = go(n-1,m-1);
            return dp[n][m] = ans;
        }else{
            int insertcall = a+go(n,m-1);
            int removecall = b+go(n-1,m);
            int replacecall = c+go(n-1,m-1);
            return dp[n][m] = min(min(insertcall,removecall),replacecall);
        }
    };
    return go(n-1,m-1);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    //convert s1 to s2 while cost of each operation is given
    int a,b,c;
    cin>>a>>b>>c;
    cout<<minDistance(s1,s2,a,b,c)<<"\n";
}

