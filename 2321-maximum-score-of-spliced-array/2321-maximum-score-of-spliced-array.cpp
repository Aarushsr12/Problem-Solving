class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int s1 = accumulate(nums1.begin(),nums1.end(),0);
         int s2 = accumulate(nums2.begin(),nums2.end(),0);
         
        int sum1 =0, sum2=0, max1=0,max2=0;
        for(int i=0; i<n; ++i){
            sum1 += nums2[i] - nums1[i];
            if(sum1 < 0){
                sum1 =0;
            }
            max1 = max(max1,sum1);
            
            
            sum2 += nums1[i] - nums2[i];
            if(sum2 < 0){
                sum2 = 0;
            }
            max2 = max(max2, sum2);
        }
        return max(s1 + max1,s2 + max2);
    }
};