class Solution {
public:
    int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; ++i){
        int pick = nums[i] + ((i>1) ? prev2 : 0); 
        int nopick = 0 + prev;
        int curr = max(pick,nopick);
        prev2 = prev;
        prev = curr;
    }
        return prev;
    }
    
    int rob(vector<int>& arr) {
        if(arr.size() == 1){
            return arr[0];
        }
         vector<int>ans1,ans2;
         for(int i=0; i<arr.size(); ++i){
             if(i != 0){
                 ans1.push_back(arr[i]);
             }
             if(i != arr.size()-1){
                 ans2.push_back(arr[i]);
             }
         }   
        return max(maximumNonAdjacentSum(ans1),maximumNonAdjacentSum(ans2));
    }
};