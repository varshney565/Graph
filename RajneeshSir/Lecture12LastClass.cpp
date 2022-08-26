        /**
 * author : shivam varshney
 * UIET KURUKSHETRA UNIVERSITY
 * ∑.⌣
 * */

#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
/*

    

*/


void solve(){
   int n,m,k,x;
   cin>>n>>m>>k>>x;
   set<int> Special;
   for(int i = 0 ; i < k ; i++){
    int t;
    cin>>t;
    t--;
    Special.insert(t);
   }
   vector<vector<pair<int,int>>> adj(n);
   for(int i = 0 ; i < m ; i++){
    int u,v,w;
    cin>>u>>v>>w;
    u--;
    v--;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
   }
   
   int a,b;
   cin>>a>>b;
   a--;b--;
   //a --> friend Location
   //b --> Your Location
   vector<vector<int>> Dist(2,vector<int>(n,INT_MAX));
   auto dj = [&](int source,int ind){
    set<pair<int,int>> PendingNodes;
    PendingNodes.insert({0,source});
    Dist[ind][source] = 0;
    while (!PendingNodes.empty()){
        auto front = *PendingNodes.begin();
        PendingNodes.erase(front);
        int cost = front.first;
        int u = front.second;
        if(Dist[ind][u] < cost){
            continue;
        }
        for(auto x : adj[u]){
            int child = x.first;
            int weight = x.second;
            if(Dist[ind][child] > cost + weight){
                PendingNodes.insert({cost+weight,child});
                Dist[ind][child] = cost+weight;
            }
        }
    }
   };
   dj(a,0);
   dj(b,1);
   int ans = INT_MAX;
   for(int i = 0 ; i < n ; i++){
    if(Special.find(i) != Special.end()){
        if(Dist[1][i] == INT_MAX || Dist[0][i] == INT_MAX)
            continue;
        if(Dist[1][i] < x){
            ans = min(ans,Dist[1][i]+Dist[0][i]);
        }
    }
   }
   if(ans == INT_MAX){
    cout<<"-1\n";
   }else{
    cout<<ans<<"\n";
   }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("./IO/input.txt","r",stdin);
        freopen("./IO/output.txt","w",stdout);
        freopen("./IO/Error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}

