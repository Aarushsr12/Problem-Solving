class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int index = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid-1]){
                h = mid;
            }
            else{
                l = mid;
            }
        }
        return -1;
    }
};