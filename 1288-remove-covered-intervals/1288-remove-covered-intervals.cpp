class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
          sort(intervals.begin(),intervals.end());
          int n = intervals.size();
          int count=n;
        
          int c = intervals[0][0];
          int d = intervals[0][1];
          for(int i=1; i<n; ++i){
            if(intervals[i][0]>=c && intervals[i][1]<=d){
                count--;
            } 
            else if(intervals[i][0]<=c && intervals[i][1]>=d){
                count--;
                c = intervals[i][0];
                d = intervals[i][1];
            }  
            else{
                c = intervals[i][0];
                d = intervals[i][1];
            }  
          }
        return count;
    }
};