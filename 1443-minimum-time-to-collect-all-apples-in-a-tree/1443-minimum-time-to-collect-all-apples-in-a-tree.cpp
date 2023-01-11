class Solution {
public:

    int dfs(int node,vector<int> adj[],vector<bool>&hasApple,int parent){
        int  time = 0;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }   
             int time_child = dfs(it,adj,hasApple,node);
            if(time_child>0 || hasApple[it]){
                time += time_child + 2;
            }          
         }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,adj,hasApple,-1);
    }
};