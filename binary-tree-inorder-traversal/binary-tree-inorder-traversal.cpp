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

//Inorder Traversal left->current->right branch
class Solution {
public:
    void visit(vector<int>&ans , TreeNode* root){
        if (!root) {
            return;
        }
        visit(ans, root->left);
        ans.push_back(root->val);
        visit(ans, root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        visit(ans,root);
        return ans;
    }
};