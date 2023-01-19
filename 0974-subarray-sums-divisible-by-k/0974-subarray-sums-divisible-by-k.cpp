class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int curr_sum = 0;
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i){
            curr_sum += nums[i];
            int rem = curr_sum % k;
            if(rem < 0){
                rem += k;
            }
            if(rem == 0){
                count++;
            }
            if(m.find(rem) != m.end()){
                count += m[rem];
            }
            m[rem]++;
        }
        return count;
    }
};