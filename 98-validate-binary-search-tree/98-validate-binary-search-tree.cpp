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
    bool isBST(TreeNode *root,long long int min,long long int max){
        if(root == NULL){
            return true;
        }
        if(root->val <=min || root->val >=max){
            return false;
        }
        bool leftans = isBST(root->left,min,root->val);
        bool rightans = isBST(root->right,root->val,max);
        
        return leftans && rightans;
    }
    bool isValidBST(TreeNode* root) {
         long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;
        return isBST(root, min, max);
    }
};