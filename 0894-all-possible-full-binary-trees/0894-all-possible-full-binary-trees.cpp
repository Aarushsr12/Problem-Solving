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
    vector<TreeNode*> solve(int n){
         if(n % 2 == 0){
            return {};
        }
        if(n == 1){
            TreeNode *root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> result;
        for(int i=1; i<n; i+=2){
            //need all nodes in the left side & right side of the root
            //which will be stored in the TreeNode* vector
            
            vector<TreeNode*> leftSideBT = solve(i);
            vector<TreeNode*> rightSideBT = solve(n-i-1);
            
            for(auto &l : leftSideBT){
                for(auto &r : rightSideBT){
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
            
        }
        return result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
       return solve(n);
    }
};