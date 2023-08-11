class Solution {
public:
    int count = 0;
    void dfs(int src,int parent,unordered_map<int,vector<pair<int,int>>> &adj){
        for(auto it : adj[src]){
            int node = it.first;
            int check = it.second;
           
            if(node != parent){
                if(check == 1){
                    count++;
                }
                dfs(node,src,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0; i<connections.size(); ++i){
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        dfs(0,-1, adj);
        return count;
    }
};