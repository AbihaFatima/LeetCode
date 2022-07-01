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
    vector<vector<int>>ans;
public:
    void visit(TreeNode* root, int level){
        if(!root) return;
        if(level == ans.size()){
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        visit(root->left,level+1);
        visit(root->right,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        visit(root,0);
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};