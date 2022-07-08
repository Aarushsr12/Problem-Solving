class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         int n = boxTypes.size();
         sort(boxTypes.begin(),boxTypes.end(),compare);   
         
         int maxW = 0;
         for(int i=0; i<n; ++i){
            int x = min(boxTypes[i][0],truckSize);
            truckSize -= x;
            maxW += (x * boxTypes[i][1]);
            if(truckSize == 0){
                break;
            }
         }       
        return maxW;
    }
};