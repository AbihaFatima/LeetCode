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
private:
    int ans=0;
    void findNum(TreeNode *root, int temp){
        if(root==NULL) return;
        temp = temp*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            ans += temp;
        }
        findNum(root->left,temp);
        findNum(root->right,temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        findNum(root,0);
        return ans;
    }
};