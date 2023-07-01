class Solution {
public:
    bool canReach(int row,int col,vector<vector<int>>&cells,int mid){
        //change the values of all the cells colors
        vector<vector<int>>matrix(row,vector<int>(col,0));
        vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0; i<mid; ++i){
            int r = cells[i][0];
            int c = cells[i][1];
            
            matrix[r-1][c-1] = 1;
        }
        //apply dfs or bfs
        queue<pair<int,int>> q;
        //store all starting nodes
        for(int i=0; i<col; ++i){
            if(matrix[0][i] == 0){
                q.push({0,i});
                //that cell is visited
                matrix[0][i] = 1;
            }
        }
        
        while(!q.empty()){
            pair<int,int> it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(auto d: directions){
                int nr = r + d.first;
                int nc = c + d.second;
                
                if(nr>=0 && nc>= 0 && nr<row && nc<col && matrix[nr][nc] == 0){
                    if(nr == row-1){
                        return true;
                    }
                    matrix[nr][nc] = 1;
                    q.push({nr,nc});
                }
                
            }
        }
        
        return false;
        
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
       //binary search approach
        int left = 0;
        int right = cells.size();
        
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(canReach(row,col,cells,mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};