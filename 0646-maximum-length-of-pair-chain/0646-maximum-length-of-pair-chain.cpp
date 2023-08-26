class Solution {
public:
    static bool compare(vector<int>&v1, vector<int>&v2){
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int count = 1;
        int prev = 0;
        for(int i=1; i<pairs.size(); ++i){
            if(pairs[i][0] > pairs[prev][1]){
                prev = i;
                count++;
            }
        }
        return count;
    }
};