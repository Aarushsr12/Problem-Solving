class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
           int x = temp[i];
            while(!s.empty() && temp[s.top()] <= x){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top() - i;
            }
             s.push(i);
        }
        return ans;
    }
};