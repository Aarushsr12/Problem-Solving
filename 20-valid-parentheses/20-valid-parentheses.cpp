class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        stack<char> s;
        for(int i=0; i<n; ++i){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                s.push(str[i]);
            }
            //if stakc is empty , but closing bracket is there
            if(s.empty() && (str[i] ==')' || str[i] == '}' || str[i] == ']')){
                return false;
            }
            if(str[i] == ')'){
                if(s.top() == '('){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            if(str[i] == '}'){
                if(s.top() == '{'){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            if(str[i] == ']'){
                if(s.top() == '['){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        //if any brackets are remaining in the stack
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};