class Solution {
public:
    void solve(string &s,int open,int close, vector<string> &par){
        //base case
        if(open == 0 && close == 0){
            par.push_back(s);
            return;
        }
        //we have alwyas the choice of open bracket until it becomes zero
        if(open > 0){
            string s1 = s;
            s1 += '(';
            solve(s1, open-1, close, par);
        }
        if(close>0 && close > open){
            string s2 = s;
            s2 += ')';
            solve(s2, open, close-1, par);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> par;
        solve(s,n,n,par);
        return par;
    }
};