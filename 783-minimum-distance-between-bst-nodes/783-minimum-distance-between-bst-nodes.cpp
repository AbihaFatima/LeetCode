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
    int prev=INT_MAX, diff=INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        if(root){
            minDiffInBST(root->left);
            diff = min(diff, abs(root->val-prev));
            prev = root->val;
            minDiffInBST(root->right);
        }
        return diff;
    }
};