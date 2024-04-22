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
//morris
class Solution {

    //same as reverse link list
    void reverseTreeLink(TreeNode *head){

        TreeNode *pre{};
        TreeNode *cur{head};
        while(cur){
            TreeNode *next = cur->right;
            cur->right=pre;
            pre=cur;
            cur=next;
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        TreeNode *dummy = new TreeNode();
        dummy->left = root;
        TreeNode *cur = dummy;
        
        while(cur){
            if(cur->left){

                TreeNode *predecessor = cur->left;
                while(predecessor->right && predecessor->right!=cur){
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr){
                    predecessor->right = cur;
                    cur = cur->left;
                }else{
                    //do it first for easy reverse link list and visit node.
                    predecessor->right = nullptr;

                    reverseTreeLink(cur->left);
                    //visit node
                    for(TreeNode *temp{predecessor};temp!=NULL;temp=temp->right){
                        ans.push_back(temp->val);
                    }
                    reverseTreeLink(predecessor);

                    cur = cur->right;
                }
            }else{
                cur = cur->right;
            }
        }
        return ans;
    }
};
