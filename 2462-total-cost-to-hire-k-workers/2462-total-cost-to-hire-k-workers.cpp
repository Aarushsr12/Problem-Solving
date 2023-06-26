class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
         int n = costs.size();
         //we have to mainatain a window which will give us minimym window
        int l = 0;
        int r = n-1;
        priority_queue<int,vector<int>,greater<int>> p1,p2;
        long long cost = 0;
        while(k--){
            while(p1.size() < candidates && l<=r){
                p1.push(costs[l]);
                l++;
            }
            while(p2.size() < candidates && l<=r){
                p2.push(costs[r]);
                r--;
            }
            long long top1 = INT_MAX;
            long long top2 = INT_MAX;
            if(p1.size() > 0){
                top1 = p1.top();
            }
            if(p2.size() > 0){
                top2 = p2.top();
            }
            if(top1 <= top2){
                cost += top1;
                p1.pop();
            }
            else{
                cost += top2;
                p2.pop();
            }
            
        }
        return cost;
    }
};