class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0; i<num.size(); ++i){
           while(s.empty() == false && s.top()>num[i] && k>0){
                //handling peak
               s.pop();
               k--;
           } 
            if(s.empty() && num[i]=='0'){
               //if stack is empty but leading zero to be avoid
               continue;
           }
           else{
               //stack is empty 
               //if the no is greater then top, simply push
               s.push(num[i]);
           } 
        }
        //cases to handle
        // 1. If it is in ascending order
        // 2. If we want to remove all elements[3rd case]
        while(s.empty() == false && k>0){
            s.pop();
            k--;
        }
        //remove all elements
        if(s.empty() == true){
            string str ="0";
            return str;
        }
        string str="";
        while(s.empty() != true){
            str += s.top();
            s.pop();           
        }
        reverse(str.begin(),str.end());
        return str;

    }
};