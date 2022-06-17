class Solution {
public:
    bool helper(int index,vector<int>& nums,int target,vector<vector<int>>&dp){
       //base case
       if(target == 0){
           return true;
       } 
       if(index == 0){
           return (nums[0] == target);
       }
       if(dp[index][target] != -1){
           return dp[index][target];
       } 
       bool noTake = helper(index-1,nums,target,dp);
       bool Take = false;
       if(nums[index] <= target){
           Take = helper(index-1,nums,target-nums[index],dp);
       }
        return dp[index][target] = noTake | Take;
    }
    bool canPartition(vector<int>& nums) {       
     int n = nums.size();    
     int sum =0;
     for(int i=0; i<n; ++i){
         sum += nums[i];
     }
     int nsum = sum/2;  
     vector<vector<int>>dp(n,vector<int>(nsum+1,-1));   
     if(sum % 2 == 0){
         return helper(n-1,nums,nsum,dp);
     }    
     else{
         return false;
     }      
    }
};