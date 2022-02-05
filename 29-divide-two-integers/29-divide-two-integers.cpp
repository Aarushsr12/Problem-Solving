#define LL long long int
class Solution {
public:
    int divide(int divi, int div) {
        long long dividend = divi;
        long long divisor = div;
        //edge cases
        //if we have INT_MIN & div -1 so using divide logic + ans;
        if(dividend <= INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        int sign = +1;
        if(dividend<0 && divisor>0 || dividend>0 && divisor <0){ 
            sign=-1;
        }
            if(dividend < 0){
            dividend = -(dividend);
            
        }
        if(divisor<0){
            divisor = -(divisor);
        
        }
        LL t=0;
        LL ans=0;
        for(int i=31; i>=0; --i){
            if(t + (divisor << i) <= dividend){
                t += divisor<<i;
                ans += 1<<i;
          
            }
        }
        return sign * ans;
    }
};