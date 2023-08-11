class Solution {
public:
    
      int minMST(vector<vector<pair<int,int>>>& adj, int V) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //minheap
        pq.push({0, 0}); //{weight, vertex}
        
        vector<bool> inMST(V, false);
        int sum = 0;
 
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
            for(auto &tmp : adj[node]) {
                
                int neighbor      = tmp.first;
                int neighbor_wt   = tmp.second;
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int val = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, val});
                adj[j].push_back({i, val});
            }
        }
        
        return minMST(adj,n);
    }
};