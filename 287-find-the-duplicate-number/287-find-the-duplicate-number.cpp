class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int rep;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1; ++i){
            int ans = nums[i] ^ nums[i+1];
            if(ans == 0){
                rep = nums[i];
                break;
            }   
        }
        return rep;
    }
};