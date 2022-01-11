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
The idea is to simply calculate the inorder traversal of the BST as it will always give sorted value
and then store all the elements in the vector
then using two pointers approach we'll find whether the value exist or not.
*/
class Solution {
private :
    vector<int> ans;
public:
    void Inorder(TreeNode* root){
        if(root != NULL){
            Inorder(root->left);
            ans.push_back(root->val);
            Inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        Inorder(root);
        int i=0, j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j] < k) i++;
            else if(ans[i]+ans[j]>k) j--;
            else return true;
        }
        return false;
    }
};