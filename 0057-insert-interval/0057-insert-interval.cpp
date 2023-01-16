class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
    
        vector<vector<int>> ans;
        int i=0;
        //case 1: when no overlapping is there between first intervals first element;
        while(i<n && intervals[i][1] < newInterval[0]){
            //[1,2] [4,8]
            ans.push_back(intervals[i]);
            i++;
        }
        //case 2: overlapping is there
        while(i<n && newInterval[1] >= intervals[i][0]){
            //[3,10],[12,16] case
            
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        //case 3 : no overlapping is there
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }
};