//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> In(n,0);
	    int ans = 0;
	    for(int i = 0 ; i < n ; i++){
	        In[i] = arr[i];
	        for(int j = i-1 ; j >= 0 ; j--){
	            if(arr[i] > arr[j]){
	                In[i] = max(In[i],In[j]+arr[i]);
	            }
	        }
	        ans = max(ans,In[i]);
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends