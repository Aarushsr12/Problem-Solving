class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int store = 0;
        int ans = INT_MIN;
        int i=0;
        int j = n-1;
        while(i<j){
            store = min(height[i],height[j]) * (j-i);
            ans = max(ans,store);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};