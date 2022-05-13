class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
            
        priority_queue<int> pq;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                int x = matrix[i][j];
                pq.push(x);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};