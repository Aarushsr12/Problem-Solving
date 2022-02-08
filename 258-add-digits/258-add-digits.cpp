class Solution {
public:
    int addDigits(int num) {
        // if(num<=9){
        //     return num;
        // }
      while(num !=0 && num>9){  
        int sum=0;
        while(num>0){
            int rem = num%10;
            num = num/10;
            sum = rem + sum;
        }
        num =  sum;
      }
        return num;
    }
};