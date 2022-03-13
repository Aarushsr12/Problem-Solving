class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        vector<vector<bool>> vis(n, vector<bool> (n,false));
        
        for(int i=0; i<dig.size(); ++i){
            int x = dig[i][0];
            int y = dig[i][1];
            vis[x][y] = true;
        }
        int count=0;
        for(int x=0; x < art.size(); ++x){
            bool flag = true;
            for(int i=art[x][0]; i<=art[x][2]; ++i){
                for(int j=art[x][1]; j<=art[x][3]; ++j){
                   if(vis[i][j] == false){
                       flag  = false;
                   }
                }
                if(flag == false){
                    break;
                }
            }
            if(flag == true){
                count++;
            }
        }
        return count;
    }
};