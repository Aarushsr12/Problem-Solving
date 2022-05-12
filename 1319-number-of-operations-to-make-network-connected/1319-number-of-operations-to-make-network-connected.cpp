class Solution {
public:
    void dfs(vector<int> adj[],vector<bool> &visited, int src){
        visited[src] = true;
        for(int it : adj[src]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<int> adj[n];
        for(int i=0; i<connections.size(); ++i){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int count =0;
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        return count-1;
    }
};