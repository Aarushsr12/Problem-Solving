class Solution {
public:
    bool check(vector<int> &heights,int bricks,int ladders,int target){
        multiset<int> r;
        for(int i=1; i<=target; i++){
            if(heights[i] > heights[i-1]){
                r.insert(heights[i] - heights[i-1]);
            }
        }
        if(r.size() <= ladders){
            return true;
        }
        for(auto it : r){
            if(bricks >= it){
                bricks = bricks-it;
            }
            else if(ladders > 0){
                ladders--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //binary search4
        int l = 0;
        int h = heights.size()-1;
        int ans = INT_MIN;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(heights,bricks,ladders, mid)){
                //if true
                ans = max(ans, mid);
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};
