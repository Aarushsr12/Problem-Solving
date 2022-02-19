class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        set<int>s;
        for(int i=0; i<n; ++i){
            if((nums[i] & 1) != 0){
                //odd case
                s.insert(nums[i]*2);
            }
            else{
                s.insert(nums[i]);
            }
        }
        
        int min_deviation = INT_MAX;
        while(1){
            int deviation = (*s.rbegin())- (*s.begin());
            min_deviation = min(min_deviation,deviation);
            int max_value = (*s.rbegin());
            if((max_value & 1) == 0){
                s.erase(max_value);
                s.insert(max_value/2);
            }
            else{
                //after reducing value even to odd
                break;
            }
        }
        return min_deviation;
    }
};