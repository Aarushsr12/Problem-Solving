class Solution {
public:
    int Min = INT_MAX;
    void dfs(int node,vector<int>&vis,vector<pair<int,int>>adj[],int n){
        vis[node] = 1;
        for(auto it : adj[node]){
            int next = it.first;
            int w = it.second;
            Min = min(Min,w);
            if(vis[next] == 0){
                
                dfs(next,vis,adj,n);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<roads.size(); ++i){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
        }
        vector<int> vis(n+1,0);
        dfs(1,vis,adj,n);
        return Min;
    }
};