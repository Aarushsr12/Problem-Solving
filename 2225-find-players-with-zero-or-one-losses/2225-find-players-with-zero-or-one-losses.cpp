class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        set<int> s1,s2;
        map<int,int>m;
\
        for(auto it : matches){
            s1.insert(it[0]);
            s2.insert(it[1]);
            m[it[1]]++;
        }
        
        vector<int> res1,res2;
        for(auto it : s1){
            if(s2.find(it) == s2.end()){
                res1.push_back(it);
            }
        }
        
        for(auto it : s2){
            if(m[it] == 1){
                res2.push_back(it);
            }
        }
       return {res1, res2}; 
    }
};