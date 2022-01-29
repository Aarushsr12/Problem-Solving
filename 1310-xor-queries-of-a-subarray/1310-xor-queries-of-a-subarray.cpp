class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //pre-fix sum
        vector<int> ans;
        vector<int> prefix(arr.size()+1110);
        for(int i=0; i<arr.size(); ++i){
            prefix[i+1] = prefix[i] ^ arr[i];
        } 
        for(int i=0; i<queries.size(); ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(prefix[r+1] ^ prefix[l]);
        }
        return ans;
    }
};