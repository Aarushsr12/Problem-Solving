class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       int n = words.size();
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string,int> m;
        for(int i =0 ; i<n; ++i){
            string str = words[i];
            string code = "";
            for(int j=0; j<str.size(); ++j){
                code += morse[str[j] - 'a'];
            }
            m[code]++;
        }
        
        return m.size();
    }
};