class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            m[nums[i]]++;
        }
        int pair = 0;
        for(auto it : m){
            int x = it.second;
            pair += (x * (x - 1))/2;            
        }
        return pair;
    }
};