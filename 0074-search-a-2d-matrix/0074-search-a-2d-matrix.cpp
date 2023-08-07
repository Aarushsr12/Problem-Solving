class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
         int m = matrix[0].size();
            
        int row = 0;
        int col = m-1;
        while(row <= n-1 && col >= 0){
            int curr = matrix[row][col];
            if(curr == target){
                return true;
            }
            else if(target > curr){
                row++;
            }
            else{
                col--;
            }
        }
        return false; 
    }
};