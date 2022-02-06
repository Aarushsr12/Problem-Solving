class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return n;
        }
        int index=0;
        for(int i=0; i<nums.size(); ++i){
            if(i<2 || nums[i] != nums[index-2]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};