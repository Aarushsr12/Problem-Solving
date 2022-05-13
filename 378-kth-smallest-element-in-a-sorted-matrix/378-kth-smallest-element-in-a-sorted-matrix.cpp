class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        k = (n*n) - k;
        
        priority_queue<int> pq;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                int x = matrix[i][j];
                pq.push(x);
            }
        }
        while(k > 0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};