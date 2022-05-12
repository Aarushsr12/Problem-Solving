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
    bool invert(TreeNode *root1, TreeNode * root2){
        // if(root1->left == root2->left){
        //     return false;
        // }
        // if(root1->right == root2->right){
        //     return false;
        // }
        // return true;
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL || root1->val != root2->val){
            return false;
        }
        return (invert(root1->left,root2->right) && invert(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return invert(root->left,root->right);
    }
};