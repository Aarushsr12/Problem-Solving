class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0; i<nums1.size(); ++i){
            m1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); ++i){
            m2[nums2[i]]++;
        }
        
        vector<int> v1;
        for(int i=0; i<nums1.size(); ++i){
            if(m2[nums1[i]] == 0){
                v1.push_back(nums1[i]);
                //now to make a check here in map
                m2[nums1[i]] = 1;
            }
        }
        ans.push_back(v1);
        
        vector<int>v2;
        for(int i=0; i<nums2.size(); ++i){
            if(m1[nums2[i]] == 0){
                v2.push_back(nums2[i]);
                m1[nums2[i]] = 1;
            }
        }
        ans.push_back(v2);
        return ans;
    }
};