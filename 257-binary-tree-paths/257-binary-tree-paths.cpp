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
The basic idea is to traverse the tree keeping the path in the string str and when you find a leaf then substituting str in the answer.We need vector answer to be same in all the calls in the call stack, therefore we use address operator while we need separate str for each step,hence not using address operator.
*/
class Solution {
private:
    vector<string>ans;
    void addPath(TreeNode* root,vector<string>&ans,string str){
        if(root==NULL) return;
        if(root->left || root->right){
            str += (to_string(root->val)+"->");
        }
        else{//last node
            str += to_string(root->val);
            ans.push_back(str);
        }
        addPath(root->left,ans,str);
        addPath(root->right,ans,str);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        addPath(root,ans,str);
        return ans;
    }
};