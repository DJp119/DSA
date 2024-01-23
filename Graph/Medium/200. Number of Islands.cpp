// BFS
// TC- O(N2)
// SC - O(N2) + O(N2)
class Solution {
    private:
    void bfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int row = grid.size();
        int col = grid[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int r= q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int newrow = r+delrow[k];
                int newcol = c+delcol[k];
                if(newrow>=0 && newrow<row &&  newcol >= 0 && newcol<col && grid[newrow][newcol]=='1'&& !vis[newrow][newcol]){
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1') {
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
    return count;
    }
};



// DFS 
// TC - O(V2)
/*
    https://leetcode.com/problems/number-of-islands/
    TC: O(V^2)
*/
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water or is already visited
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        // do DFS in all 4 directions
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // We can treat the matrix grid as a grid. Each Island is a
        // connected component. The task is to find no. of disconnectedd components
        // in the graph.
        
        int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};
