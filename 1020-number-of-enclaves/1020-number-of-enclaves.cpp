class Solution {
public:
    int count=0;
    bool flag = true;
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        //base case
        if(i<0 || j<0 || i>=n || j>=m){
            flag = false;
            return;
        }
        if(grid[i][j] == 0 || grid[i][j] == 2){
            return;
        }
        count++;
        grid[i][j]=2;

        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                count=0;
                flag = true;
                if(grid[i][j] == 1){
                    dfs(grid,i,j,n,m);
                    if(flag){
                        size += count;
                    }
                }
            }
        }
        return size;
    }
};