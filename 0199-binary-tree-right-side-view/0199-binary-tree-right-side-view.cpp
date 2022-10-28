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
Approach:
1. Traverse the whole tree in level order fashion using BFS along with storing the last processed node (here it is stored in curr).
2. Keep a tag ( here nullptr) at the end of each level to know that a particular level has ended.
3. Whenever a level ends store the last processed node value to the ans vector.
4. Return ans.
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        // Initially push the root node
        q.push(root);
        // Then push null, as level=0 contains only the root node
        q.push(NULL);
        
        TreeNode *curr;
        
        while(!q.empty()){
            if(q.front()!=NULL){// if the end of current level is not reached
                // keep the current node
                curr = q.front();
                // push the left and right child of curr node into the queue if exists
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            // nullptr signifies the end of the current level, so need to add the last element of this level to ans
            else{
                // last element of the level = last deleted element of queue from front
                // curr contains the last deleted element of queue from front
                ans.push_back(curr->val);
                q.pop();
                
                //if the queue is not empty then again push nullptr to keep a tag at the end of the next level
                if(!q.empty())
                    q.push(NULL);
            }
        }
        return ans;
    }
};