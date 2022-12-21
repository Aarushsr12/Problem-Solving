class Solution {
public:
    bool bipartitebfs(int node,vector<int> adj[],vector<int> &sep){
        //apply bfs
        queue<int>q;
        q.push(node);
        sep[node] = 1;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it : adj[ele]){
                if(sep[it] == -1){
                    sep[it] = 1 - sep[ele];
                    q.push(it);
                }
                else if(sep[it] == sep[ele]){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkDislikes(vector<int> adj[],int n){
        vector<int> sep(n+1,-1);
        for(int i=1; i<=n; ++i){
            if(sep[i] == -1){
                if(!bipartitebfs(i,adj,sep)){
                    return false;
                }
            }
        }
        return true;
    } 
        
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(int i=0; i<dislikes.size(); ++i){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(checkDislikes(adj,n)){
            return true;   
        }
        else{
            return false;
        }

    }
};