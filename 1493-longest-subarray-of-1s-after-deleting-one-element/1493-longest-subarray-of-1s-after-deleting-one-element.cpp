class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int result = 0;
        int lastindex = -1;
        while(j < nums.size()){
            if(nums[j] == 0){
                i = lastindex + 1;
                lastindex = j;
            }
            result = max(result,j-i);
            j++;
        }
        return result;
    }
};