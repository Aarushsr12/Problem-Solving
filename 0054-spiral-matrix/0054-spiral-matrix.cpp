class Solution {
public:
    vector<int> ans;
    void right(int &i,int &j, vector<vector<int>> &matrix){
        for( ; j<matrix[0].size(); ++j){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    void down(int &i,int &j,vector<vector<int>> &matrix){
        for( ; i<matrix.size(); ++i){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    void left(int &i,int &j,vector<vector<int>> &matrix){
        for( ; j>=0; j--){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    void up(int &i, int &j, vector<vector<int>> &matrix){
        for( ; i>=0; i--){
            if(matrix[i][j] == INT_MAX){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int count = matrix.size() * matrix[0].size();
       int i=0;
       int j=0;
      while(ans.size() < count){
          //R D L U
          right(i,j,matrix);
          j--;
          i++;
          down(i,j,matrix);
          i--;
          j--;
          left(i,j,matrix);
          i--;
          j++;
          up(i,j,matrix);
          i++;
          j++;   
      }
       return ans;
    }
};