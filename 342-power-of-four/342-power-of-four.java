#define ll long long int
class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n>0){
            count++;
            n = n>>1;
        }
        return count;
    }
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if((n &(n-1)) == 0){
            if(countbits(n)%2 == 0){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
};