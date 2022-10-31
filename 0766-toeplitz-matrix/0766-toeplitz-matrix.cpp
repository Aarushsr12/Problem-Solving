class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        for(int i=1; i<M; ++i){
            int res = matrix[0][i];
            
            int l = 0;
            int m = i;
            
            while(l<N && m < M){
                if(matrix[l][m] != res){
                    return false;
                }
                l++;
                m++;
            }
        }
        
        for(int i=N-1; i>=0; i--){
            int res = matrix[i][0];
            
            int l = i;
            int m = 0;
            while(l<N && m < M){
                if(matrix[l][m] != res){
                    return false;
                }
                l++;
                m++;
            }
        }
        return true;
    }
};