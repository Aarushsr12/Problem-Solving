class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int,int> mp;
        int sum1=0;
        for(int i=0; i<nums1.size(); ++i){
            for(int j=0; j<nums2.size(); ++j){
                sum1 = nums1[i] + nums2[j];
                mp[sum1]++;
            }
        }   
        //O(n^2)
        
        //in first two arrays we look for sum1 total value & then will search for it in next 2arrays
        int sum2=0;
        for(int i=0; i<nums3.size(); ++i){
            for(int j=0; j<nums4.size(); ++j){
                sum2 = (-1 )* (nums3[i] + nums4[j]);
            
                if(mp[sum2]){
                    count+=mp[sum2];
                }
            }
        }
        //O(n^2)
        return count;
    }
};