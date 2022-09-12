#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(bool t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
inline void read(int &n,vector<int> &v){for(int i = 0 ; i < n ; i++) cin>>v[i];}
inline void print(int &n,vector<int> &v){for(int i = 0 ; i < n ; i++) cout<<v[i]<<" ";cout<<"\n";}
inline void read(int &n,int &m,vector<vector<int>> &v){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>v[i][j];}}}
inline void print(int &n,int &m,vector<vector<int>> &v){for(int i=0 ;i<n;i++){for(int j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<"\n";}}

int LDS_brute_force_dp(int n,vector<int> &v){
    vector<int> dp(n,1);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i - 1 ; j >= 0 ; j--){
            if(v[j] > v[i]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int LDS_optimsed(int n,vector<int> v){
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        auto it = lower_bound(ans.begin(),ans.end(),v[i],greater<int>());
        if(it == ans.end()) ans.push_back(v[i]);
        else ans[it-ans.begin()] = v[i];
    }
    return ans.size();
}

void solve(){
   int n;
   cin>>n;
   vector<int> v(n);
   read(n,v);
   int ans = LDS_optimsed(n,v);
   cout<<ans<<"\n";
}

signed main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

