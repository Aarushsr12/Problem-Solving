class Solution {
public:
    //during this question I observed dijkstra algorithm we have to find shortest path
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //we will do dfs first
        // as we move to path we will check first node to be start
        //and as we encounter the end node we will stop and calculate the total value of the             array
       vector<pair<int,double>> adj[n];
       for(int i=0; i<edges.size(); ++i){
           int u = edges[i][0];
           int v = edges[i][1];
           
           adj[u].push_back({v,succProb[i]});
           adj[v].push_back({u,succProb[i]});
       } 
        priority_queue<pair<int,double>,vector<pair<int,double>>> pq;
        vector<double> dist(n,0);
        pq.push(make_pair(1,start));
        dist[start] = 1;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                double wt = it.second;
                
                if(dist[v] < dist[u] * wt){
                    dist[v] = dist[u] * wt;
                    pq.push({dist[v],v});
                }
                
            } 
        }
        
        return dist[end];
        
        
    }
};