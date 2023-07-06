class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int minLen = INT_MAX;
        while(j < n){
            sum += nums[j];
            if(sum < target){
                j++;
            }
            if(sum >= target){
                while(sum >= target){
                    minLen = min(minLen,j - i +1);
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};