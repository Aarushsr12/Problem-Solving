class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n= nums.size();
        vector<int>v;
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                v.emplace_back(i+1);
                v.emplace_back(j+1);
                break;
            }
        }
        return v;
    }
};