class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int maxSize = 0;
        int i = 0;
        
        while(i < s.size()) {
            int j = i;
            int localSize = 0;
            map<char, int> store;
            while(j < s.size() && store.find(s[j]) == store.end()) {
                store.insert({s[j],1});
                j++;
                localSize++;
            }
            if(localSize > maxSize)
                maxSize = localSize;
            i++;
        }
        return maxSize;
    }
};