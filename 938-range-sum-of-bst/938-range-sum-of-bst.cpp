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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int cal = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();
            if(front != NULL){
                 if(front->val >= low && front->val <= high){
                cal += front->val;
            }
            if(front->val > low){
                q.push(front->left);
            }
            if(front->val <= high){
                q.push(front->right);
            }
            }
        }
        return cal;
    }
};