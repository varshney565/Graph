#include<bits/stdc++.h>
using namespace std;
//LeetcodeQuestionsNothingNewConcept
//Leetcode 695
 class dsu{
    public:
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
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
        s[p2] += s[p1];
        return true;
    }
};

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    dsu D(n*m);
    bool ok = false;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!grid[i][j]) continue;
            ok = true;
            for(int k = 0 ; k < 4 ; k++){
                int newI = i+dir[k][0];
                int newJ = j+dir[k][1];
                if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1){
                    D.unite(i*m+j,newI*m+newJ);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n*m ; i++){
        if(D.p[i] == i){
            ans = max(ans,D.s[i]);
        }
    }
    if(!ok) return 0;
    return ans;
}


//Leetcode 839
bool isSimilar(string a,string b){
    int cnt = 0;
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        if(a[i] != b[i])
            cnt++;
        if(cnt > 2)
            return false;
    }
    return true;
}

int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    int compo = n;
    dsu D(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(isSimilar(strs[i],strs[j])){
                if(D.unite(i,j))
                    compo--;
            }
        }
    }
    return compo;
}



//Leetcode 1905
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    function<void(int,int,int&)> dfs = [&](int x,int y,int &val){
        if(grid1[x][y] == 0){
            val = -1;
        }
        grid2[x][y] = 0;
        for(int i = 0 ; i < 4 ; i++){
            int newX = x+dir[i][0];
            int newY = y+dir[i][1];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid2[newX][newY] == 1){
                dfs(newX,newY,val);
            }
        }
    };
    
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid2[i][j] == 1){
                int t = 0;
                dfs(i,j,t);
                if(t == 0)
                    cnt++;
            }
        }
    }
    return cnt;
}

//Leetcode 305 (LintCode 434)
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int cnt1 = 0;
        vector<int> ans;
        dsu D(n*m);
        for(int i = 0 ; i < operators.size() ; i++){
            auto x = operators[i];
            if(grid[x.x][x.y] == 1){
                ans.push_back(cnt1);
                continue;
            }
            grid[x.x][x.y] = 1;
            cnt1++;
            for(int k = 0 ; k < 4 ; k++){
                int newI = dir[k][0] + x.x;
                int newJ = dir[k][1] + x.y;
                if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1){
                    if(D.unite(x.x*m+x.y,newI*m+newJ))
                        cnt1--;
                }
            }
            ans.push_back(cnt1);
        }
        return ans;
    }
};


/**
 * initially total number of SCC = 0
 * if we put a 1 at position (x,y) and there is no one at the four sides of this node 
 * than it will increase the count of SCC by 1 else decrease the count by number of edges connected
 * 
 * won't work
 * e.g : 
 * 
 * 1 1 1 1 1 1
 * 1 0 0 0 0 1
 * 1 1 ? 1 1 1
 **/