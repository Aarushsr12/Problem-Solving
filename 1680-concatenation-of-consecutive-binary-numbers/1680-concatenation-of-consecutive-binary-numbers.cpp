class Solution {
public:
    int concatenatedBinary(int n) {
        long long int val = 0;
        for(int i=1; i<=n; ++i){
            val = ((val << (1 + (int)(log2(i)))) + i) % 1000000007; 
        }
        return val;
    }
};