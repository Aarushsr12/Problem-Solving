class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        vector<int> ind;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == target){
                ind.push_back(i);
            }
        }
        int size = ind.size();
        int random = ind[rand() % size];
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */