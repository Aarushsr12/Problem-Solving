class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<int,vector<int> ,greater<int>> pq(nums.begin(),nums.end());
        int i=0;
        while(pq.empty()!=true)
        {
            
            nums[i]=pq.top();
            pq.pop();
            i++;
            
        }
        
        return nums;
        
        
    }
};