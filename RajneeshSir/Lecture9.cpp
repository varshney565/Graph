//Prism --> Graph is given or graph is demse
//Krushkal --> Graph is not given or graph is sparsh
//Leetcode 743

#include<bits/stdc++.h>
using namespace std;
//Not Better according to time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0],v = times[i][1],w = times[i][2];
            u--;v--;
            graph[u].push_back({v,w});
        }
        k--;
        set<vector<int>> PendingNodes;
        PendingNodes.insert({0,k,-1,0});
        vector<int> visited(n,false);
        int ans = 0;
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int wsf = front[0];
            int u = front[1];
            int p = front[2];
            int w = front[3];
            if(visited[u]){
                continue;
            }
            visited[u] = true;
            ans = max(ans,wsf);
            for(int i = 0 ; i < graph[u].size() ; i++){
                pair<int,int> v = graph[u][i];
                if(!visited[v.first]){
                    PendingNodes.insert({wsf+v.second,v.first,u,v.second});
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
                return -1;
        }
        return ans;
    }
};


// Dijkrashta Better ...
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0],v = times[i][1],w = times[i][2];
            u--;v--;
            graph[u].push_back({v,w});
        }
        k--;
        set<vector<int>> PendingNodes;
        PendingNodes.insert({0,k});
        vector<int> dis(n,INT_MAX);
        vector<int> visited(n,false);
        vector<int> parent(n,-1);
        dis[k] = 0;
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int wsf = front[0];
            int src = front[1];
            if(visited[src])
                continue;
            visited[src] = true;
            for(auto child : graph[src]){
                if(!visited[child.first] && dis[src]+child.second < dis[child.first]){
                    dis[child.first] = dis[src]+child.second;
                    PendingNodes.insert({dis[child.first],child.first});
                    parent[child.first] = src;
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};

//BellMan Ford : Works For both +ve and -ve edges
//Leetcode 787
class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        int E = flights.size();
        vector<int> dis(V,INT_MAX);
        dis[src] = 0;
        for(int i = 1 ; i <= k ; i++){
            vector<int> disU(V,INT_MAX);
            for(int i = 0 ; i < V ; i++){
                disU[i] = dis[i];
            }
            bool ok = false;
            for(int j = 0 ; j < E ; j++){
                int u = flights[j][0],v = flights[j][1],w = flights[j][2];
                if(dis[u] == INT_MAX)
                    continue;
                int cost = dis[u]+w;
                if(cost < disU[v]){
                    disU[v] = cost;
                    ok = true;
                }
            }
            swap(disU,dis);
            if(!ok)
                break;
        }
        return (dis[dst]==INT_MAX)?-1:dis[dst];
    }
};