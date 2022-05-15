class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(int i=1; i<n; ++i){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};