class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
        string str="";
        int t=0,sum=0,count=0;
            
        for(int i=0; i<s.size(); ++i){
            t = s[i]-'0';
            sum += t;
            count++;
            if(count == k){
               str += to_string(sum);
                sum =0;
                count=0;
            }
        }
        if(count > 0){
            str += to_string(sum);
         }
          s = str;  
            
        }
        return s;
        
    }
};