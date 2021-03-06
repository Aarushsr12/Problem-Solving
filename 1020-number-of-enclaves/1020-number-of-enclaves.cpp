class Solution {
public:
    int count=0;
    
    bool dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        //base case
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        if(grid[i][j] == 0 || grid[i][j] == 2){
            return true;
        }
        count++;
        grid[i][j]=2;

        bool d1 = dfs(grid,i+1,j,n,m);
        bool d2 = dfs(grid,i-1,j,n,m);
        bool d3 = dfs(grid,i,j-1,n,m);
        bool d4 = dfs(grid,i,j+1,n,m);
        
        return d1 && d2 && d3 && d4;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                count=0;
                if(grid[i][j] == 1){
                    if(dfs(grid,i,j,n,m)){
                        size += count;
                    }
                }
            }
        }
        return size;
    }
};