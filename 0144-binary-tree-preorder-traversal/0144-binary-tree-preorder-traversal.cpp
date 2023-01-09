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
    vector<int>ans;
    void pre(TreeNode *root){
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left) pre(root->left);
        if(root->right) pre(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return ans;
    }
};