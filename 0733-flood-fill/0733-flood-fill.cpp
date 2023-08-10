class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int n,int m,int color,int initial){
        //bases cases
        if(sr < 0 || sc < 0){
            return;
        }
        if(sr > n-1 || sc > m -1){
            return;
        }
        if(image[sr][sc] != initial){
            return;
        }
        //color given cell
        image[sr][sc] = color;
        dfs(image,sr+1,sc,n,m,color,initial);
        dfs(image,sr,sc+1,n,m,color,initial);
        dfs(image,sr-1,sc,n,m,color,initial);
        dfs(image,sr,sc-1,n,m,color,initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        
        if(initial != color){
            dfs(image,sr,sc,n,m,color,initial);
        }
        return image;
    }
};