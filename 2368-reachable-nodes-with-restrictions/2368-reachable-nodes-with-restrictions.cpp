class Solution {
public:
    int count = 0;
    void dfs(int node,vector<int>&vis, vector<int>adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                count++;
                dfs(it,vis,adj);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        
        for(int i=0; i<edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(int i=0; i<restricted.size(); ++i){
            vis[restricted[i]] = 1;
        }
        dfs(0,vis,adj);
        return count + 1;
    }
};