class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_end=0;
        int max_so_far=0;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0){
                max_end+=(-1);
            }
            else{
                max_end += 1;
            }
            
            if(max_end == 0){
                max_so_far = i+1;
            }
            else if(m.count(max_end)){
                max_so_far = max(max_so_far,(i-m[max_end]));
            }
            else{
                m[max_end] = i;
            }
        }
        return max_so_far;
    }
};