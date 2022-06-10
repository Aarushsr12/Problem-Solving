class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &size){
        //base case
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != 1){
            return;
        }
        grid[i][j] = 2;
        size++;
        dfs(grid,i+1,j,n,m,size);
        dfs(grid,i-1,j,n,m,size);
        dfs(grid,i,j+1,n,m,size);
        dfs(grid,i,j-1,n,m,size);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
            
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1){
                    int size = 0;
                    dfs(grid,i,j,n,m,size);
                    ans = max(ans,size);
                }
            }
        }
        return ans;
    }
};