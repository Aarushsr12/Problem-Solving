class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; ++i){
            //0 is not the negative
            int pick = nums[i] + ((i>1) ? prev2 : 0);
            int nopick = 0 + prev;
            int curr = max(pick, nopick);
            prev2 = prev;
            prev = curr;
        }
    return prev;
    }
};