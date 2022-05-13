class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(; i<n-1; ++i){
            if(heights[i] < heights[i+1]){
                int diff = heights[i+1] - heights[i];
                pq.push(diff);
                
                if(pq.size() > ladders){
                    bricks -= pq.top();
                    pq.pop();
                    if(bricks < 0){
                        break;
                    }
                }
            }
        }
        return i;
    }
};