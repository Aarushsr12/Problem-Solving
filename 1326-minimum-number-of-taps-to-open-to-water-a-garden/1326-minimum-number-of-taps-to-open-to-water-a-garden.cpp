class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min =0;
        int max =0;
        int count=0;
        int index=0;
        
        while(max < n){
            for(int i=index; i<ranges.size(); ++i){
                if(i-ranges[i]<=min && i+ranges[i]>max){
                    max = i+ranges[i];
                    index=i;
                }
            }
            if(max == min){
                return -1;
            }
            count++;
            min = max;
        }
        return count;
   }
};