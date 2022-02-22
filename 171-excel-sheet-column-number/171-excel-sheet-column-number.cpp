class Solution {
public:
    int titleToNumber(string str) {
         //breakdown BCA into BC _ A
        int n = str.size();
        int sum = str[0] - 'A' + 1;
        for(int i=1; i<n; ++i){
            int c = str[i]-'A'+1;
            sum = (sum * 26) + c; 
        }
        return sum;
    }
};  