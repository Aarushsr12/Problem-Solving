class Solution {
public:
    void dfs(vector<vector<int>>&graph,int src,int target,vector<vector<int>>&result,vector<int>&temp){
       
        temp.push_back(src);
        if(src == target){
            result.push_back(temp);
        }
        else{
            for(auto it : graph[src]){
                dfs(graph,it,target,result,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0;
        int target = n- 1;
        
        vector<vector<int>> result;
        vector<int>temp;
        dfs(graph,src,target,result,temp);
        return result;
    }
};