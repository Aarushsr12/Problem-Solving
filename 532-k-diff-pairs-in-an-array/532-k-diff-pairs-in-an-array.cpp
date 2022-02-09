class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>s;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size();++i){
            if(m.find(nums[i] + k) != m.end()){
                s.insert(make_pair(nums[i],nums[i] + k));
            }
            if(m.find(nums[i] - k) != m.end()){
                s.insert(make_pair(nums[i] - k,nums[i]));
            }
            m[nums[i]]++;
        }
        return s.size();
    }
};