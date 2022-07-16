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
Pre-order Traversal Approach
TC: O(N)
SC: O(N)
*/
class Solution {
    void getAllPath(TreeNode *root, int targetSum, vector<int>path, vector<vector<int>> &ans){
        if(!root) return;
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            path.push_back(root->val);
            ans.push_back(path);
        }
        path.push_back(root->val);
        getAllPath(root->left,targetSum-root->val,path,ans);
        getAllPath(root->right,targetSum-root->val,path,ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        getAllPath(root,targetSum,{},ans);
        return ans;
    }
};