/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
     if(root == NULL){
        return -1;
     }
     priority_queue<long long> pq;
     queue<TreeNode*> q;
     q.push(root);

     while(!q.empty()){
         int n = q.size();
          long long sum = 0;
         for(int i=0; i<n; ++i){
            TreeNode* front = q.front();
            q.pop();
            sum += front->val;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
         }
         pq.push(sum);
     }
     if(pq.size() < k){
        return -1;
     }
     //if nth largest then k = k-1;
    k = k-1;
     while(k--){
        pq.pop();
     }
     return pq.top();
    }
};