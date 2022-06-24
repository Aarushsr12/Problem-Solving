class Solution {
public:
    int helper(vector<int>& nums,int index,int target,int n){
        //base case
        if(index == n){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pos = helper(nums,index+1,target-nums[index],n);
        int neg = helper(nums,index+1,target-(-nums[index]),n);
        return pos + neg;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums,0,target,n);
    }
};