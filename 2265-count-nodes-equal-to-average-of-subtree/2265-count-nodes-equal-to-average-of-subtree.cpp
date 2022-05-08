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
    void countNodes(TreeNode *root,int &cnt){
        if(root == NULL){
            return;
        }
        cnt++;
        countNodes(root->left,cnt);
        countNodes(root->right,cnt);
    }
    int average(TreeNode *root,int &count){
        if(root == NULL){
            return 0;
        }
        //post order traversal 
        int sum = average(root->left,count) + average(root->right,count) + root->val;
        int cnt=0;
        countNodes(root,cnt);
        if(sum/cnt == root->val){
            count++;
        }
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        average(root,count);
        return count;
    }
};