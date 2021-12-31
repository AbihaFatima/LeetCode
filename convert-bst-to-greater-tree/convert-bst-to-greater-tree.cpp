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


/*
1. Go deep to the right most lead
2. Return back maintain a count variable
3. Assign the count to current root->val
4. Recur for left if not NULL
*/
class Solution {
public:
    int curr_sum =0;
    void Sum(TreeNode *root){
        if(root==NULL){
            return;
        }
        if(root->right){
            Sum(root->right);
        }
        curr_sum += root->val;
        root->val = curr_sum;
        if(root->left){
            Sum(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        Sum(root); 
        return root;
    }
};