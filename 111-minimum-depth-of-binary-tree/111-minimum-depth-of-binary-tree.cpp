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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftans = minDepth(root->left);
        int rightans = minDepth(root->right);
        
        if(leftans == 0 || rightans == 0){
            return 1 + max(leftans,rightans);
        }
        return 1 + min(leftans,rightans);
        
        
    }
};