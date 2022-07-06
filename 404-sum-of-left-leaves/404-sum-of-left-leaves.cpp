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
    //Function to check if the curr node is a leaf node or not
    bool checkLeaf(TreeNode* root){
        if(root->left == NULL && root->right==NULL) return true;
        return false;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        
        queue<pair<TreeNode*,bool>>q;
        q.push({root,false});
        
        while(!q.empty()){
            pair<TreeNode*,bool> node = q.front();
            q.pop();
            
            TreeNode *curr = node.first;
            bool isLeft = node.second;
            
            if(isLeft==true && checkLeaf(curr)==true) sum += curr->val;
            
            if(curr->left) q.push({curr->left,true});
            if(curr->right) q.push({curr->right,false});
        }
        return sum;
    }
};