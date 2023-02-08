class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps=1;
        if(n==1 || nums[0]==0){
            return 0;
        }
        int far = nums[0];
        int curr = nums[0];
        for(int i=1; i<n; ++i){
            if(i==n-1){
                return jumps;
            }
            far = max(far,i+nums[i]);
            if(i==curr){
                jumps++;
                curr = far;
         }
        }
        return jumps;
    }
};