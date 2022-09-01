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
    int count = 0;
    void goodNodes(TreeNode* root,int ans){
        //base case
        if(root == NULL){
            return;
        }
        if(root->val >= ans){
            count++;
            ans = root->val;
        }
        goodNodes(root->left,ans);
        goodNodes(root->right,ans);
    }
    int goodNodes(TreeNode* root) {
        goodNodes(root,INT_MIN);
        return count;
    }
};