class Solution {
public:
    long long calculate(vector<int>&piles,int h,int k){
        long long total = 0;
        for(int i=0; i<piles.size(); ++i){
            total += ceil( (double)piles[i] / (double)k ); 
        }
        return total;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
         int n = piles.size();
         //pointer reflect the k speed
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            long long total_time = calculate(piles,h,mid);
            if(total_time <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};