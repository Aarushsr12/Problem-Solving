class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
        while(i<nums.size()){
            int j=i;
            while(j+1 < nums.size()  && nums[j+1] == nums[j]+1){
                j++;
            }
            if(i == j){
                string x = to_string(nums[i]);
                ans.push_back(x);
            }
            else{
                //if there is a range>1
                string x = to_string(nums[i])+"->"+to_string(nums[j]);
                ans.push_back(x);
            }
            i = ++j;
        }
        return ans;
    }
};