class Solution {
public:
    void solve(string digits,int index,vector<string> &comb,map<char,string> &m,string s){
        //base case
        if(index == digits.size()){
            comb.push_back(s);
            return;
        }
        for(auto it : m[digits[index]]){
            solve(digits, index+1, comb, m ,s + it);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> comb;
        string s = "";
        map<char,string> m;
        m['2'] = "abc"; m['3'] = "def"; m['4'] = "ghi"; m['5'] = "jkl"; m['6'] = "mno";
        m['7'] = "pqrs"; m['8'] = "tuv"; m['9'] = "wxyz";
        
        if(digits == ""){
            return comb;
        }
        solve(digits,0,comb,m,s);
        return comb;
    }
};