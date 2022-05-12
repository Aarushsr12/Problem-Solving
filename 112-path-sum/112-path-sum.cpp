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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //base case
        if(root == NULL){
            return false;
        }
        targetSum = (targetSum) - (root->val);
        //hypothesis
        if(targetSum == 0 && root->left == NULL && root->right == NULL){
            return true;
        }
        //recursive step
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
        
    }
};