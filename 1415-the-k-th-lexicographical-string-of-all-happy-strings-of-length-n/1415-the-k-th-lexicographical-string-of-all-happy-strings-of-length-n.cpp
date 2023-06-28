class Solution {
public:
    vector<char> v = {'a', 'b', 'c'};
    void dfs(vector<string>&ans,int n,string &str,char prev){
        if(n == 0){
            ans.push_back(str);
            return;
        }
        
        for(int i = 0; i<v.size(); ++i){
            if(prev != v[i]){
                str.push_back(v[i]);
                dfs(ans,n-1,str,v[i]);
                str.pop_back();
            }    
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> ans;
        string str="";
        dfs(ans,n,str,'#');
        if(ans.size() < k){
            return "";
        }
        return ans[k-1];
    }
};