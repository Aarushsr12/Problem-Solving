class Solution {
public:
  
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        for(auto it : m){
            p.push({it.second, it.first});
        }
        while(p.size() > k){
            p.pop();
        }

        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
        
    }
};