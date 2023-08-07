class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
         int m = matrix[0].size();
            
         int l = 0;
         int h = n *m - 1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            int check = matrix[mid / m][mid % m];
            if(check == target){
                return true;
            }
            else if(check > target){
                h = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};