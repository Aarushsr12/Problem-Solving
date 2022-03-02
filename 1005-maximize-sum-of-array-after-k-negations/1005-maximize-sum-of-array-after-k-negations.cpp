class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); ++i){
           if(nums[i] < 0){ 
               if(k == 0){
                   break;
               }
                nums[i] *= - 1;
                 k--;
           }
        }
        int min_pos = min_element(nums.begin(),nums.end()) - nums.begin(); 
        while(k>0){
            nums[min_pos] *= -1;
            k--;
        }
        int sum=0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        return sum;
    }
};