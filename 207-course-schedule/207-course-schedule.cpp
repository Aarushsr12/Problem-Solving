class Solution {
public:
    bool checkCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto edge : adj[node]){
            if(!vis[edge]){
                if(checkCycle(edge,adj,vis,dfsvis)){
                    return true;
                }
            }
            else if(dfsvis[edge]){
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsvis)){
                    return false;
                }
            }
        }
        return true;
    }
};