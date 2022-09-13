#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
//Hint1 : what if ending points are in increasing order?
//Hint2 : What if we follow hint 1 and make sure starting points are also in the increasing order.will 
//they overlap???























int solve(vector<vector<int>> &v,int n){
    sort(v.begin(),v.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    
    vector<int> LIS(n,1);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            if(v[i][0] > v[j][0] && v[i][1] > v[j][1]){
                LIS[i] = max(LIS[i],LIS[j]+1);
            }
        }
        ans = max(ans,LIS[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 2 ; j++){
            cin>>v[i][j];
        }
    }
    cout<<solve(v,n)<<"\n";
    return 0;
}