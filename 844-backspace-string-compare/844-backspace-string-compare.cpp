class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        string str1="";
        string str2="";
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '#' && s1.empty() == false){
                s1.pop();
            }
            else if(s[i] != '#'){
                s1.push(s[i]);
            }
        }
        for(int i=0; i<t.size(); ++i){
            if(t[i] == '#' && s2.empty() == false){
                s2.pop();
            }
            else if(t[i] != '#'){
                s2.push(t[i]);
            }
        }
        while(!s1.empty()){
            str1 += s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            str2 += s2.top();
            s2.pop();
        }
        if(str1 == str2){
            return true;
        }
        else{
            cout << str1 <<endl;
            cout << str2 <<endl;
            return false;
        }
    }
};