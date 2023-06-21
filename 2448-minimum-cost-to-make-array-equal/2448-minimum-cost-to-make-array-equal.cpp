#define ll long long int
class Solution {
public:
    long long int findcost(vector<int>&nums,vector<int>&cost,int target){
        int n = nums.size();
        ll result = 0;
        for(int i=0; i<n; ++i){
            result += (ll)abs(nums[i]- target) * cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
         // we use binary search to optimize this ques
          ll ans = 0;  
          int left = *min_element(nums.begin(),nums.end());
          int right = *max_element(nums.begin(),nums.end());
        
          while(left<=right){
              int mid = left + (right - left) / 2;
              
              ll cost1 = findcost(nums,cost,mid);
              ll cost2 = findcost(nums,cost,mid+1);
                
              ans = min(cost1,cost2);
              
              if(cost2 > cost1){
                  right = mid-1;
              }
              else{
                  left = mid + 1;
              }
          }  
        return ans;
    }
};