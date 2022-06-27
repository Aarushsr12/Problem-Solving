class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<bool> &visited,vector<bool>                        &dfsvisited,vector<bool> &pre_cycle)
    {
        visited[node] = true;
        dfsvisited[node] = true;
        
        for(auto it : graph[node]){
            if(!visited[it]){
                if(dfs(it,graph,visited,dfsvisited,pre_cycle)){
                    return pre_cycle[node] = true;
                }
            }
            else if(visited[it] && dfsvisited[it]){
                return pre_cycle[node] = true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n, false);
        vector<bool> pre_cycle(n, false);
        
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(i,graph,visited,dfsvisited,pre_cycle);        
            }
        }
        vector<int>ans;
        for(int i=0; i<pre_cycle.size(); ++i){
            if(!pre_cycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};