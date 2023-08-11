class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int &node_count,int &edge_count){
        vis[node] = 1;
        node_count++;
        edge_count += adj[node].size();
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it,vis,adj,node_count,edge_count);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        vector<int>vis(n,0);
        for(int i=0; i<n; ++i){
            if(vis[i] == 0){
                int node_count = 0;
                int edge_count = 0;
                
                dfs(i,vis,adj,node_count,edge_count);
                if(edge_count == node_count * (node_count - 1)){
                    count++;
                }
            }    
        }
        return count;
    }
};