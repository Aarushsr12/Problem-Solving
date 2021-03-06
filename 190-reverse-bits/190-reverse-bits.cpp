class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=31; i>=0; --i){
            if((n & (1<<i))){
                int mask = 1<<((31)-i);
                ans = ans|mask;
            }
        }
        return ans;
    }
};