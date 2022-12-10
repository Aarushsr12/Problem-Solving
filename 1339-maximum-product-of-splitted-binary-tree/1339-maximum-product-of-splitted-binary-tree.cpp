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
    long maxP = 0;
    long SUM = 0;
    
    int totalSum(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int leftsum =  totalSum(root->left);
        int rightsum = totalSum(root->right);
        
        long subTreeSum = root->val + leftsum + rightsum;
        long remainTreeSum = SUM - subTreeSum;
        maxP = max(maxP, remainTreeSum * subTreeSum);
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        SUM = totalSum(root);
        
        totalSum(root);
        
        return maxP % (1000000007);
        
    }
};