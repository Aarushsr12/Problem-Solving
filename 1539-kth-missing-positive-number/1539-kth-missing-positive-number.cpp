class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n = arr.size();
        map<int,int> m;
        vector<int> v;
        int ans  = 0;
        for(int i=0; i<arr.size(); ++i){
            m[arr[i]]++;
        }
        for(int i=1; i<= arr[n-1]; ++i){
            if(m[i] != 1){
                v.push_back(i);
            }
        }
        if(v.size() < k){
            int rem = k - v.size();
             int x = arr[n-1];
            while(rem--){
              x++;
            }
            ans = x;
        }
        else{
            for(int i=0; i<v.size(); ++i){
                if(i+1 == k){
                    ans =  v[i];
                }
            }
        }
        return ans;
        
        
        
    }
};