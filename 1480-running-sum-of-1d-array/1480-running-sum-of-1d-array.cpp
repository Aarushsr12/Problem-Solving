class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        //pf will be zero index
        vector<int> pf(n);
        pf[0] = nums[0];
        for(int i=1 ;i<n; ++i){
           pf[i] = pf[i-1] + nums[i];
         }
        return pf;
    }
};