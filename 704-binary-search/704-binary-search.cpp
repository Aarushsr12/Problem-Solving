class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        if(nums.size() ==1){
            if(nums[0] == target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target){
                  ans = mid;
                    break;
            }
            if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};