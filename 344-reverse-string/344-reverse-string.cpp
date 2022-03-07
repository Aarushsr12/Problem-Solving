class Solution {
public:
    void reverseString(vector<char>& s) {
        //two pointer approach
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
};