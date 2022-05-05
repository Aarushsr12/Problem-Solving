class Solution {
public:
    bool search(int i,int j, int n,int m,vector<vector<char>> &board,string word,int index){
        //search conditions
        if(i>=0 && i<n && j>=0 && j<m && board[i][j] != '#'){
            if(board[i][j] == word[index]){
                index++;
            }
            else{
                return false;
            }
            if(index == word.size()){
                return true;
            }
            char temp = board[i][j];
            board[i][j] ='#';
            
            if(search(i-1,j,n,m,board,word,index)){
                return true;
            }
            if(search(i+1,j,n,m,board,word,index)){
                return true;
            }
            if(search(i,j-1,n,m,board,word,index)){
                return true;
            }
            if(search(i,j+1,n,m,board,word,index)){
                return true;
            }
            board[i][j] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j] == word[0]){
                    if(search(i,j,n,m,board, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};