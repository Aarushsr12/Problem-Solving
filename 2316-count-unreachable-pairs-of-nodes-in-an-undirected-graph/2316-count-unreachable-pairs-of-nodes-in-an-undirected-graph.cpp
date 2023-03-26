class Solution {
public:
    void dfs(int src,vector<int> adj[],vector<int> &vis,long long &size){
       vis[src] = 1;
        size++;
        for(auto it : adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis,size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0);
       long long remain_nodes = n;
       long long result = 0;
        
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                long long size = 0;
                dfs(i,adj,vis,size);
                result += (size) * (remain_nodes - size);
                remain_nodes -= size;
            }
        }
        return result;
    }
};