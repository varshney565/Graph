#include<bits/stdc++.h>
using namespace std;

//Krushkal Algo
class dsu{
    public: 
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};
vector<vector<int>> Krushkal(vector<vector<int>> &Edges){
    sort(Edges.begin(),Edges.end(),[](const vector<int>& a,const vector<int>&b){
        return a[2] < b[2];
    });
    int n = Edges.size();
    dsu D(n);
    vector<vector<int>> ans;
    for(int i = 0 ; i < n ; i++){
        if(D.unite(Edges[i][0],Edges[i][1]))
            ans.push_back(Edges[i]);
    }
    return ans;
}

//optimise water distriboution in a village
// Leetcode 1168

//Mr. Precident hackerearth
//Note : Use Fast IO
class dsu{
    public:
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }

    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> Edges;
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        Edges.push_back({u,v,w});
    }
    vector<int> w;
    sort(Edges.begin(),Edges.end(),[](const vector<int> &a,const vector<int> &b){
        return a[2] < b[2];
    });

    dsu D(n);
    int cost = 0;
    int cnt = n;
    for(int i = 0 ; i < m ; i++){
        bool ok = D.unite(Edges[i][0],Edges[i][1]);
        if(ok) w.push_back(Edges[i][2]),cnt--,cost += Edges[i][2];
    }
    if(cnt > 1){
        cout<<"-1\n";
        return;
    }
    int ans = 0;
    for(; w.size() > 0 ;){
        if(cost <= k){
            break;
        }
        cost -= w.back();
        cost++;
        w.pop_back();
        ans++;
    }
    if(cost > k) cout<<"-1\n";
    else cout<<ans<<"\n";
}

//Leetcode 1584
int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<int>> Edges;
    int n = points.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            Edges.push_back({i,j,w});
        }
    }
    sort(Edges.begin(),Edges.end(),[](const vector<int>&a,const vector<int>&b){
        return a[2] < b[2];
    });
    dsu D(n);
    int dist = 0;
    for(int i = 0 ; i < Edges.size() ; i++){
        if(D.unite(Edges[i][0],Edges[i][1])){
            dist += Edges[i][2];
        }
    }
    return dist;
}


