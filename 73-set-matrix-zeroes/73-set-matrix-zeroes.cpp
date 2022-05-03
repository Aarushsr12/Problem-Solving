class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<vector<int>> q;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            vector<int> m = q.front();
            for(int j = 0; j<matrix[m[0]].size(); ++j){
                matrix[m[0]][j] = 0;
            }
            for(int i =0; i<matrix.size(); ++i){
                matrix[i][m[1]] = 0;
            }
            q.pop();
        }
    }
};