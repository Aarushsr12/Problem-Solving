class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int> adj[],int n){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it,vis,adj,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n; ++i){
            if(vis[i] == 0){
                dfs(i,vis,adj,n);
                count++;
            } 
        }
        return count;
    }
};