class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //bfs
        queue<string> q;
        unordered_set<string> vis;
        
        q.push(start);
        vis.insert(start);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; ++i){
                string node = q.front();
                q.pop();
                
                // rear end cond.
                if(node == end){
                    return count;
                }
                for(char ch : "ACGT"){
                    for(int j=0; j<node.size(); ++j){
                        string str = node;
                        str[j] = ch;
                        if(!vis.count(str) && find(bank.begin(),bank.end(),str) != bank.end()){
                            q.push(str);
                            vis.insert(str);
                        }
                    }
                }
                
            }
            count++;
        }
        return -1;
    }
};