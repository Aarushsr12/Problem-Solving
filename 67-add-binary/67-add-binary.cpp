class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0;
        int n1 = a.size();
        int n2 = b.size();
        
        int carry = 0;
        string str="";
        while(i<n1 || i<n2 || carry != 0){
            int x =0;
            if(i<n1 && a[n1 - i-1] == '1'){
                x = 1;
            }
            int y =0;
            if(i<n2 && b[n2 - i -1] == '1'){
                y = 1;
            }
            str = to_string((x + y + carry) % 2) + str;
            carry = (x + y + carry) / 2;
            i++;
        }
            
        return str;
    }
};