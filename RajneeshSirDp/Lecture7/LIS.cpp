#include<bits/stdc++.h>
using namespace std;

//Nlogn
/**
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
            if(it == ans.end()){
                ans.push_back(nums[i]);
            }else{
                ans[it-ans.begin()] = nums[i];
            }
        }
        return ans.size();
    }
};**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        function<int(int)> go = [&](int ei){
            if(dp[ei] != -1)
                return dp[ei];
            int ans = 1;
            for(int i = ei-1 ; i >= 0 ; i--){
                if(nums[ei] > nums[i]){
                    ans = max(ans,1+go(i));
                }
            }
            return dp[ei] = ans;
        };
        int ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            ans = max(ans,go(i));
        }
        return ans;
    }
};