class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int> ans;
        sort(p.begin(),p.end());
        
        for(int i=0; i<s.size(); ++i){
            int l = 0;
            int r = p.size()-1;
            int mid = 0;
            while(l <= r){
                mid = l + (r-l) / 2;
                
                if((long long int)s[i] * (long long int)p[mid] >= success){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
           ans.push_back(p.size() - r - 1);
            
        }
        return ans;
    }
};