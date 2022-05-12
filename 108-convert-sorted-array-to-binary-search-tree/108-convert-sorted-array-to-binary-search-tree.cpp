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
    //Divide & Conquer Algorithm
    TreeNode *sortedArray(vector<int> &nums,int start,int end){
        //base case
        if(start > end){
            return NULL;
        }
        int mid = start + (end - start)/2;
        int mid_elem = nums[mid];
        TreeNode *root = new TreeNode (mid_elem);
        root->left = sortedArray(nums,start,mid-1);
        root->right = sortedArray(nums,mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        return sortedArray(nums,start,end);
    }
};