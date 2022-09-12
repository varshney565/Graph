//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums){
	    int n = nums.size();
	    vector<int> In(n,1);
	    vector<int> Dec(n,1);
	    for(int i = 0 ; i < n ; i++)
	        for(int j = i - 1 ; j >= 0 ; j--)
	            if(nums[j] < nums[i])
	                In[i] = max(In[i],In[j]+1);
	    
	    for(int i = n - 1 ; i >= 0 ; i--)
	        for(int j = i + 1 ; j < n ; j++)
	            if(nums[i] > nums[j])
	                Dec[i] = max(Dec[i],Dec[j]+1);
	    int ans = 1;
	    for(int i = 0 ; i < n ; i++)
	        ans = max(ans,In[i]+Dec[i]-1);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends