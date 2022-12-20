class Solution {
public:
    
    bool PathCheck(vector<vector<int>>&adj,int n,vector<int>&vis,int source,int destination){
      //main conditon
        if(source == destination){
            return true;
        }
        if(vis[source] == true){
            return false;
        }
        vis[source] = 1;
        for(auto it : adj[source]){
            if(PathCheck(adj,n,vis,it,destination)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination){
            return true;
        }
        
        vector<vector<int>> adj(n+1);
        for(int i=0; i<edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n+1,0);
        
       return PathCheck(adj,n,vis,source,destination);
        
    }
};