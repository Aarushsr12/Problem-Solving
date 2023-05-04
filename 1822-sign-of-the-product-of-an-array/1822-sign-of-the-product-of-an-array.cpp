class Solution {
public:
    int arraySign(vector<int>& nums) {
        //use brain first
        //agar array diya ho uska multiplication sirf uske signs se find kar sakte hain
        int ans = 0;
        int pos = 0, neg = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0){
                return 0;
            }
        }
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] >= 0){
                pos++;
            }
            else{
                neg++;
            }
        }
        if(neg %2 == 1){
            return -1;
        }
        else{
            return 1;
        }
    }
};