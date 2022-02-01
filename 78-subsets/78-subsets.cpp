class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerset;
        int n = nums.size();
        for(int i=0; i<(1<<n); ++i){
            vector<int>set;
            for(int bit=0; bit<n; bit++){
                if(i & (1<<bit)){
                    set.push_back(nums[bit]);
                }
            }
            powerset.push_back(set);
        }
        return powerset;
    }
};