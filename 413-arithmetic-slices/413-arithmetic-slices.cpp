class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int prev = INT_MIN;
        int count=0,ans=0;
        for(int i=1; i<n; ++i){
            int curr = nums[i] - nums[i-1];
            if(curr == prev){
                count++;
            }
            else{
                count=0;
            }
            prev = curr;
            ans += count;
        }
        return ans;
    }
};