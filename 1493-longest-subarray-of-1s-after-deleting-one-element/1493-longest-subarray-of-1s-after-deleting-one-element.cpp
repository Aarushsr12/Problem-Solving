class Solution {
public:
    int findMax(vector<int>&nums,int index){
         int curr = 0;
         int maxLength = 0; 
        for(int i=0; i<nums.size(); ++i){
             if(i == index){
                 continue;
             }
             if(nums[i] == 1){
                 curr++;
                 maxLength = max(maxLength,curr);
             }
             else{
                 curr = 0;
             }
         }
        return maxLength;
    }
    int longestSubarray(vector<int>& nums) {
         int n = nums.size();
         int result = 0;
         int zero = 0;
        for(int i=0; i<n; ++i){
            if(nums[i] == 0){
                zero++;
                result = max(result,findMax(nums,i));
            }
        }
        if(zero == 0){
            return n - 1;
        }
        return result;
    }
};