class Solution {
public:
    void visitRoom(int node,vector<vector<int>> &rooms,vector<int> &vis){
       vis[node] = 1;
        for(auto it : rooms[node]){
            if(!vis[it]){
                visitRoom(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        //all should be visited
        vector<int> vis(n,0);
        visitRoom(0,rooms,vis);
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};