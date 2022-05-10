class Solution {
public:
    bool Palindrome(string s,int i,int j,int count){
        if(count > 1){
            return false;
        }
        while(i<j){
            if(s[i] != s[j]){
                return (Palindrome(s, i+1, j, count+1) || Palindrome(s, i, j-1, count+1));
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        return Palindrome(s, 0 , s.size()-1,0);
    }
};