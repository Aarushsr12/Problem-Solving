class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //sliding window
        if(s1.size() > s2.size()) return false;
        vector<int> f1(26,0), f2(26,0);
        int i;
        for(i=0; i<s1.size(); ++i){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1 == f2){
            return true;
        }
        int start=0;
        int end = i;
        while(end < s2.size()){
            //remove char from start & add in end window
            f2[s2[start]-'a']--;
            f2[s2[end]-'a']++;
            if(f1 == f2){
                return true;
            }
            start++;
            end++;
        }
        return false;
    }
};