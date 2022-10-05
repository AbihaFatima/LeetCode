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
    //DFS Approach
    //TC:O(N)
    //SC:O(N)
    void addRow(TreeNode* root, int val, int depth, int level){
        if(!root) return;
        if(level+1 == depth){
            TreeNode *l=root->left, *r=root->right;
            root->left = new TreeNode(val,l,NULL);
            root->right = new TreeNode(val,NULL,r);
            return;
        }
        addRow(root->left,val,depth,level+1);
        cout<<level<<endl;
        addRow(root->right,val,depth,level+1);
        cout<<level<<endl;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val,root,NULL);
        int level=1;
        addRow(root,val,depth,level);
        return root;
    }
};