class Solution {
public:
    int Euclidean(int x,int y){
        return pow(x,2) + pow(y,2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i=0; i<n; ++i){
            int x2 = points[i][0];
            int y2 = points[i][1];
            
            int dist = Euclidean(x2, y2);
            pq.push({dist, i});
            while(pq.size() > k){
                pq.pop();
            }
       }
       while(!pq.empty()){
           ans.push_back(points[pq.top().second]);
           pq.pop();
       } 
        return ans;
    }
};