//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}
// } Driver Code Ends


int maxSumBS(int arr[] , int n ){
    vector<int> In(n,0);
    vector<int> Dec(n,0);
    //LISS
    for(int i = 0 ; i < n ; i++){
        In[i] = arr[i];
        for(int j = i - 1 ; j >= 0 ; j--){
            if(arr[j] < arr[i]){
                In[i] = max(In[i],In[j]+arr[i]);
            }
        }
    }
    //LDSS
    for(int i = n - 1 ; i >= 0 ; i--){
        Dec[i] = arr[i];
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[i]){
                Dec[i] = max(Dec[i],Dec[j]+arr[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans,In[i]+Dec[i]-arr[i]);
    }
    return ans;
}
