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

//Recursive Approach

// class Solution {
// private:
//     vector<vector<int>> ans;
    
// public:
//     void visit(TreeNode* root, int level){
//         if (!root){
//             return;
//         }
//         if (level == ans.size()){
//             ans.push_back({});
//         } 
//         ans[level].push_back(root->val);
//         visit(root->left, level+1);
//         visit(root->right, level+1);
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         visit(root,0);
//         return ans;
//     }


//                  Iterative BFS Approach
class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*>q;
            q.push(root);
            vector<vector<int>> ans;
            if(!root) return ans;
            while(!q.empty()){
                vector<int>row;
                int Qsize = q.size();
                while(Qsize--){
                    TreeNode *node = q.front();
                    row.push_back(node->val);
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                ans.push_back(row);
            }
            return ans;
        }
};