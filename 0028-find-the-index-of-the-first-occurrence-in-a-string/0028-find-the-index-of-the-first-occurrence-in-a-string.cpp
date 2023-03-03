class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int ans = -1;
        for(int i=0; i<haystack.size(); ++i){
                string str = haystack.substr(i,needle.size());
                if(str == needle){
                    ans = i; 
                    break;
                }
        }
        return ans;
    }
};