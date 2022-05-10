class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //using pointers on the strings
        //iterate till the common part
        int min_size = strs[0].size();
        for(int i=1; i<strs.size(); ++i){
            int len = strs[i].size();
            min_size = min(min_size, len);
        }
        string ans;
        char check;
        for(int i=0; i<min_size; ++i){
            check = strs[0][i];
            for(int j=1; j<strs.size(); ++j){
                if(strs[j][i] != check){
                    return ans;
                }
            }
            ans += check;
        }
        return ans;
    }
};