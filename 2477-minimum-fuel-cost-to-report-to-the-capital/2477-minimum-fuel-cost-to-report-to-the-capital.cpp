class Solution {
public:
    long long ans = 0;
    int dfs(int src,vector<int> &vis,vector<int> adj[],int seats){
        vis[src] = 1;
        long long count = 1;
        for(auto it : adj[src]){
            if(vis[it] == 0){
                count += dfs(it,vis,adj,seats);
            }
        }
        long long x = count/seats;
        if(count % seats){
            x++;
        }
        if(src != 0){
            ans += x;
        }
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int>adj[n];
        for(int i=0; i<roads.size(); ++i){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int>vis(n,0);
        dfs(0,vis,adj,seats);
        return ans;
    }
};