//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        int n = s.size();
        long long ai = 0;
        long long aibj = 0;
        long long aibjck = 0;
        const int mod = 1e9+7;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a'){
                ai += ai+1LL;
                ai %= mod;
            }else if(s[i] == 'b'){
                aibj += (aibj+ai);
                aibj %= mod;
            }else if(s[i] == 'c'){
                aibjck += aibjck+aibj;
                aibjck %= mod;
            }
        }
        return aibjck;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends