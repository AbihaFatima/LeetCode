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
    int ans=0;
    void inorder(TreeNode* root, int maxVal){
        if(root==NULL) return;
        if(root->val >= maxVal){
            ans++;
            maxVal = root->val;
        }
        inorder(root->left,maxVal);
        inorder(root->right,maxVal);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return ans;
        inorder(root, root->val);
        return ans;
    }
    
};