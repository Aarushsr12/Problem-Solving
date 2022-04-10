class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> p;
        for(int i=0; i<nums.size(); ++i){
            p.push(nums[i]);
        }
        while(k--){
            int x = p.top();
            p.pop();
            x++;
            p.push(x);
        }
        
        long long int mod = 1e9 + 7,mul = 1;
        
        while(!p.empty()){
            mul = (mul * p.top()) % mod;
            p.pop();
        }    
        return mul;
    }
    
};