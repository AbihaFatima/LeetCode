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
    //TimeComplexity : O(N)
    //SpaceComplexity : O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> TreeQueue;
        TreeQueue.push(root);
        
        bool leftToRight = true;
        
        while(!TreeQueue.empty()){
            
            int size = TreeQueue.size();
            vector<int>row(size);
            
            for(int i=0;i<size;i++){
                TreeNode* node = TreeQueue.front();
                TreeQueue.pop();
                
                int index = (leftToRight) ? i : (size-1-i);//if leftToRight is true push nodes left to right normally as in level order traversal
                //else set the index to last i.e pushing it from right to left
                row[index] = node->val;
                
                if(node->left){
                    TreeQueue.push(node->left);
                }
                if(node->right){
                    TreeQueue.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};