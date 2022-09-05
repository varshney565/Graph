#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> go(int n,vector<int> &cnt){
    if(n == 0){
        return {{}};
    }
    if(n == 1){
        return {{{cnt[n-1]}}};
    }
    vector<vector<vector<int>>> ans;
    //single
    auto Single = go(n-1,cnt);
    for(auto &x : Single){
        x.push_back({cnt[n-1]});
        ans.push_back(x);
    }
    //pair
    for(int i = n-2 ; i >= 0 ; i--){
        swap(cnt[i],cnt[n-2]);
        auto Pair = go(n-2,cnt);
        for(auto &x : Pair){
            x.push_back({cnt[n-1],cnt[n-2]});
            ans.push_back(x);
        }
        swap(cnt[i],cnt[n-2]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> cnt(n);
    for(int i = 0 ; i < n ; i++){
        cnt[i] = i+1;
    }

    auto ans = go(n,cnt);
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<"[";
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout<<"[";
            for(int k = 0 ; k < ans[i][j].size() ; k++){
                cout<<ans[i][j][k]<<" ";
            }
            cout<<"] ";
        }
        cout<<"]\n";
    }
    return 0;
}