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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int answer=0;
        while(!q.empty()){
            int count = q.size();
            int minAtLevel = q.front().second;
            int mn,mx;
            for(int i=0;i<count;i++){
                TreeNode *node = q.front().first;
                int currIdx = q.front().second - minAtLevel +1;
                q.pop();
                if(i==0) mn=currIdx;
                if(i==count-1) mx=currIdx;
                if(node->left!=NULL) q.push({node->left, 2LL*currIdx});
                if(node->right!=NULL) q.push({node->right,(2LL*currIdx) +1});
            }
            answer = max(answer, mx-mn+1);
        }
        return answer;
    }
};