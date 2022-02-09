class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //if k == 0 ,find the i having it.second > 1;
        //if k>0 ,find the i having i + k;
        unordered_map<int,int> m;
        for(auto it :nums){
            m[it]++;
        }
        int count=0;
        for(auto it : m){
            if((k==0 && it.second>1) || (k>0 && m.find(it.first + k) != m.end())){
                count++;
            }
        }
        return count;
    }
};