class Solution {
public:
    string convertToTitle(int num) {
        string str="";
        while(num>0){
            int a = num%26;
            num = num/26;
            if(a == 0){
                num--;
            }
            char c;
            if(a == 0){
                c='Z'; 
            }        
            else{
                c = ((a-1) + 'A'); 
            }  
            str = c+str;
        }   
        return str;
    }
};