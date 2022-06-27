class Solution {
public:
    bool dfs(int src,vector<vector<int>> &graph,vector<int> &color){
        //initially mark them as unsafe
        color[src] = 1;
        //cycle detection in directed graph
        for(auto it : graph[src]){
            if(color[it] == 0 && dfs(it,graph,color) || color[it] == 1){
                return true;
            }
        }
        
        color[src] =2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n);
        vector<int> ans;
        for(int i=0; i<n; ++i){
            if(color[i] == 2 || dfs(i,graph,color) == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};