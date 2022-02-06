class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //since each element is appearing at most twice
        //start pointers after the 2 poistions
        int n = nums.size();
        if(n<3){
            return n;
        }
        int i=2;
        for(int j=2; j<n; ++j){
            if(nums[j] != nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};