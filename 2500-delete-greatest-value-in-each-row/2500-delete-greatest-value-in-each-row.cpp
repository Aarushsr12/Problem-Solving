class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; ++i){
            sort(grid[i].begin(),grid[i].end(),greater<>());
            //new syntax sort(a.begin(),a.end(),greater<>());
        }
        int total = 0;
        for(int i=0; i<m; ++i){
            int val = grid[0][i];
            for(int j=1; j<n; ++j){
                val = max(val , grid[j][i]);        
            }
                 total += val;
        }
    return total;
        
        
        
    }
};