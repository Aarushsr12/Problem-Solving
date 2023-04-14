class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i){
            m[arr[i]]++;
        }
        vector<int> freq;
        for(auto it : m){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        for(int i=0; i<freq.size()-1; ++i){
            if(freq[i] == freq[i+1]){
                return false;
            }
        }
        return true;
    }
};