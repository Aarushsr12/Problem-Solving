class Solution {
public:
    vector<int> ans;
    //right
    void right(int &i,int &j,vector<vector<int>> &matrix){
        for( ; j<matrix[0].size(); ++j){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }     
    }
    //down
    void down(int &i,int &j,vector<vector<int>> &matrix){
        for( ;i<matrix.size(); ++i){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }    
    }
    //left
    void left(int &i,int &j,vector<vector<int>> &matrix){
        for( ;j>=0; j--){
           if(matrix[i][j] == INT_MAX){
               return;
           } 
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    //up
    void up(int &i,int &j,vector<vector<int>> &matrix){
        for( ;i>=0; i--){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //no.of times we have to loop
        //ans.size() == matrix.size() * matrix[0].size();
        int i=0;
        int j=0;
        int element_count = matrix.size() * matrix[0].size();
        while(ans.size() < element_count){
            right(i,j,matrix);
            ++i;
            --j;
            down(i,j,matrix);
            --j;
            --i;
            left(i,j,matrix);
            ++j;
            --i;
            up(i,j,matrix);
            ++i;
            ++j;
        }
        return ans;
    }
};