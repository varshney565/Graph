//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

//Count Total Subsequences of Type 
//ai,bj,ck,dz,ey,fl
class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        int n = s.size();
        vector<int> t(6,0);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a'){
                t[0] += t[0]+1;
            }else{
                t[s[i]-'a'] = 2*t[s[i]-'a']+t[s[i]-'a'-1];
            }
        }
        return t[5];
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