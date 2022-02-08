class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
    int ans=0;
    if(s.size()<=1){
        ans = num;
    }
    while(s.size()>1){
      int sum=0;
      for(int i=0; i<s.size(); ++i){
        sum = sum + (s[i]-'0');
      }
       s = to_string(sum); 
       ans = sum;
    }  
        return ans;
    }
};