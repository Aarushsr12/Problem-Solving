class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt;
        int curr = 0;
        alt.push_back(curr);
        for(int i=0; i<n; ++i){
            curr += gain[i];
            alt.push_back(curr);
        }
        return *max_element(alt.begin(), alt.end());
    }
};