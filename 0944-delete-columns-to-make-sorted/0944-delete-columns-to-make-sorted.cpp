class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        int count=0;
        for(int j=0; j<m; ++j){
            
            string s =" ";
            for(int i=0; i<n; ++i){
                s += strs[i][j];
            }
            
            string t = s;
            sort(t.begin(),t.end());
            if(t != s){
                count++;
            }
        }
        return count;
    }
};