class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        
        for(int i=0; i<=n; ++i){
            int bit=0;
            int num = i;
            while(num !=0){
                num = num & num-1;
                bit++;
            }
            v.push_back(bit);
        }
        return v;
    }
};