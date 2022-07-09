class Solution {
public:
    long maxDiff(vector<int>& cuts,int length){
        sort(cuts.begin(),cuts.end());
        int max_diff = cuts[0];
        for(int i=1; i<cuts.size(); ++i){
            max_diff = max(max_diff,cuts[i]-cuts[i-1]);
        }
        max_diff = max(max_diff,length-cuts[cuts.size()-1]);
        return max_diff;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
         long x = maxDiff(horizontalCuts, h);
         long y = maxDiff(verticalCuts, w);
        
        return (x*y) % 1000000007;
    }
};