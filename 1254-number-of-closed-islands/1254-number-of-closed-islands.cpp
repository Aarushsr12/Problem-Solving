class Solution {
public:
    bool dfs(vector<vector<int>> &grid,int i,int j,int n,int m){
        //base case
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }
        grid[i][j] = 1;
        //four movements
        bool m1 = dfs(grid,i+1,j,n,m);
        bool m2 = dfs(grid,i-1,j,n,m);
        bool m3 = dfs(grid,i,j+1,n,m);
        bool m4 = dfs(grid,i,j-1,n,m);
        
        return m1 & m2 & m3 & m4;        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        for(int i=0; i<n; ++i){
            for(int j=0;  j<m; ++j){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j,n,m)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};