class Solution {
public:
    void dfs(int src,vector<int> adj[],vector<bool> &vis){
        vis[src] = true;
        for(auto it : adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //not enough cables
        if(connections.size() < n-1){
            return -1;
        }
        
        vector<int> adj[n];
        for(int i=0; i<connections.size(); ++i){
            int x = connections[i][0];
            int y = connections[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> vis(n, false);
        //count the no of connected components
        int count = 0;
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count-1;
    }
};