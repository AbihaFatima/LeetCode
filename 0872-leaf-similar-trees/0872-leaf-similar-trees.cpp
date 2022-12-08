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
 https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg*/
class Solution {
    bool isLeafNode(TreeNode* node){
        if(node->left == NULL && node->right == NULL) return true;
        return false;
    }
    void dfs(TreeNode* root, vector<int> &v){
        if(!root) return;
        if(isLeafNode(root)) {
            v.push_back(root->val);
        }
        dfs(root->left,v);
        dfs(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a{};
        vector<int>b{};
        dfs(root1,a);
        dfs(root2,b);
        if(a==b) return true;
        return false;
    }
};