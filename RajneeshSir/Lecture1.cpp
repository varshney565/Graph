#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &adj,int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

//Q1 : print the graph
//Time Complexity : E1 + E2 + E3 + .... + E(v-1) = 2*E = O(E)
void display(vector<vector<pair<int,int>>> &adj,int V){
    for(int u = 0 ; u < V ; u++){
        cout<<u<<" --> ";
        for(auto v : adj[u]){
            cout<<"(";
            cout<<v.first<<","<<v.second;
            cout<<") ";
        }
        cout<<"\n";
    }
}

//Q2 : Remove an Edge from the graph
//Time Complexity : O(E)
void removeEdge(vector<vector<pair<int,int>>> &adj,int u,int v){
    auto it = adj[u].begin();
    for(auto x : adj[u]){
        if(x.first == v){
            adj[u].erase(it);
            //or swap that element with last index and erase the last element
            break;
        }
        it++;
    }

    it = adj[v].begin();
    for(auto x : adj[v]){
        if(x.first == u){
            adj[v].erase(it);
            break;
        }
        it++;
    }
}

//Q3 : Remove Vertex from the graph
//Time Complexity : O(E)
void removeVtx(vector<vector<pair<int,int>>> &adj,int u){
    for(int v = adj[u].size() - 1 ; v >= 0 ; v--){
        pair<int,int> Edge = adj[u][v];
        //i have to remove the edege from u to Edge.first
        adj[u].pop_back();
        //and also from Edge.first to u
        for(int x = 0 ; x < adj[Edge.first].size() ; x++){
            pair<int,int> Edge2 = adj[Edge.first][x];
            if(Edge2.first == u){
                swap(adj[Edge.first][x],adj[Edge.first][adj[Edge.first].size()-1]);
                adj[Edge.first].pop_back();
                break;
            }
        }
    }
}

//Q4 : has path and count the total number of paths from source to destination


/**
HasPath : 
1.mark
2.dfs on all neighbours
  2.1
**/

bool hasPathHelper(vector<vector<pair<int,int>>> &adj,int src,int dest,vector<bool> &visited){
    if(src == dest) return true;
    visited[src] = true;
    for(int i = 0 ; i < adj[src].size() ; i++){
        pair<int,int> Edge = adj[src][i];
        if(!visited[Edge.first] && hasPathHelper(adj,Edge.first,dest,visited))
            return true;
    }
    return false;
}

/**
TotalPaths or FindAllPaths : 
1.mark
2.dfs on all neighbours
  2.1
3.unmark
**/
void TotalPaths(vector<vector<pair<int,int>>> &adj,int src,int dest,vector<bool> &visited,int &ans){
    if(src == dest){
        ans++;
        return;
    }
    visited[src] = true;
    for(int i = 0 ; i < adj[src].size() ; i++){
        pair<int,int> Edge = adj[src][i];
        if(visited[Edge.first]){
            continue;
        }
        TotalPaths(adj,Edge.first,dest,visited,ans);
    }
    visited[src] = false;
}

int hasPath(vector<vector<pair<int,int>>> &adj,int src,int dest){
    int ans = 0;
    vector<bool> visited(adj.size(),false);
    TotalPaths(adj,src,dest,visited,ans);
    return ans;
}


//Q5 : preorder of the given graph
void preorder(vector<vector<pair<int,int>>> &adj,int u,vector<bool> &visited,string path,int cost){
    visited[u] = true;
    path += '|';
    path += to_string(u);
    cout<<u<<"-->"<<path<<" @ "<<cost<<"\n";
    for(int i = 0 ; i < adj[u].size() ; i++){
        pair<int,int> Edge = adj[u][i];
        if(!visited[Edge.first]){
            preorder(adj,Edge.first,visited,path,cost+Edge.second);
        }
    }
    visited[u] = false;
}


//Q6 : Heavhy path
void Helper(vector<vector<pair<int,int>>> &adj,int src,int dest,vector<bool>& visited,string path,int weight,string &PathAns,int &WeightAns){
    path += "|";
    path += to_string(src);

    if(src == dest){
        if(WeightAns < weight){
            WeightAns = weight;
            PathAns = path;
        }
        return;
    }

    visited[src] = true;
    for(int i = 0 ; i < adj[src].size() ; i++){
        pair<int,int> Edge = adj[src][i];
        if(!visited[Edge.first]){
            Helper(adj,Edge.first,dest,visited,path,weight+Edge.second,PathAns,WeightAns);
        }
    }
    visited[src] = false;
}

pair<int,string> HeavyPath(vector<vector<pair<int,int>>> &adj,int src,int dest){
    int weight = 0;
    string path = "";
    string PathAns = "";
    int WeightAns = 0;
    vector<bool> visited(adj.size(),false);
    Helper(adj,src,dest,visited,path,weight,PathAns,WeightAns);
    return {WeightAns,PathAns};
}


int main(){
    int V = 9;
    vector<vector<pair<int,int>>> adj(V);
    addEdge(adj,0,1,10);
    addEdge(adj,0,3,10);
    addEdge(adj,2,1,10);
    addEdge(adj,3,2,40);
    addEdge(adj,2,7,2);
    addEdge(adj,2,8,4);
    addEdge(adj,7,8,3);
    addEdge(adj,3,4,2);
    addEdge(adj,4,5,2);
    addEdge(adj,5,6,3);
    addEdge(adj,4,6,8); 
    cout<<"Graph : \n";
    display(adj,V);

    cout<<"Finding The Path\n";
    cout<<hasPath(adj,0,6)<<"\n";
    cout<<hasPath(adj,0,12)<<"\n";

    cout<<"Heaviest Path from o to 6 is : \n";
    auto ans = HeavyPath(adj,0,6);
    cout<<ans.first<<" "<<ans.second<<"\n";

    cout<<"preorder : \n";
    vector<bool> visited(V,false);
    preorder(adj,0,visited,"",0);

    cout<<"Removing Edge\n";
    removeEdge(adj,0,1);

    cout<<"Graph after Removing the Edge\n";
    display(adj,V);

    cout<<"RemovingVertex 2\n";
    removeVtx(adj,2);
    cout<<"vertexRemoved\n";
    cout<<"Now the graph is : \n";
    display(adj,V);

    return 0;
}

/**
Graph : 
0 --> (1,10) (3,10)
1 --> (0,10) (2,10)
2 --> (1,10) (3,40) (7,2) (8,4)
3 --> (0,10) (2,40) (4,2) 
4 --> (3,2) (5,2) (6,8)
5 --> (4,2) (6,3)
6 --> (5,3) (4,8)
7 --> (2,2) (8,3)
8 --> (2,4) (7,3)
Finding The Path
4
0
Heaviest Path from o to 6 is :
70 |0|1|2|3|4|6
preorder :
0-->|0 @ 0
1-->|0|1 @ 10
2-->|0|1|2 @ 20
3-->|0|1|2|3 @ 60
4-->|0|1|2|3|4 @ 62
5-->|0|1|2|3|4|5 @ 64
6-->|0|1|2|3|4|5|6 @ 67
6-->|0|1|2|3|4|6 @ 70
5-->|0|1|2|3|4|6|5 @ 73
7-->|0|1|2|7 @ 22
8-->|0|1|2|7|8 @ 25
8-->|0|1|2|8 @ 24
7-->|0|1|2|8|7 @ 27
3-->|0|3 @ 10
2-->|0|3|2 @ 50
1-->|0|3|2|1 @ 60
7-->|0|3|2|7 @ 52
8-->|0|3|2|7|8 @ 55
8-->|0|3|2|8 @ 54
7-->|0|3|2|8|7 @ 57
4-->|0|3|4 @ 12
5-->|0|3|4|5 @ 14
6-->|0|3|4|5|6 @ 17
6-->|0|3|4|6 @ 20
5-->|0|3|4|6|5 @ 23
Removing Edge
Graph after Removing the Edge
0 --> (3,10)
1 --> (2,10)
2 --> (1,10) (3,40) (7,2) (8,4) 
3 --> (0,10) (2,40) (4,2)
4 --> (3,2) (5,2) (6,8)
5 --> (4,2) (6,3)
6 --> (5,3) (4,8)
7 --> (2,2) (8,3) 
8 --> (2,4) (7,3)
RemovingVertex 2
vertexRemoved
Now the graph is :
0 --> (3,10)
1 -->
2 -->
3 --> (0,10) (4,2)
4 --> (3,2) (5,2) (6,8) 
5 --> (4,2) (6,3)
6 --> (5,3) (4,8)
7 --> (8,3)
8 --> (7,3) 
*/