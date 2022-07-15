/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Time Complexity: O(N)
Space Complexity: O(N) => we're using 2 hashmaps and 1 queue
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //BFS traversal mark the parent nodes
        unordered_map<TreeNode*, TreeNode*>parent;// node -> parent
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        q.push(target);
        visited[target] = true;
        int curr_level=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode *curr = q.front();
                q.pop();
                //Traverse left node
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                //Traversing right node
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                //Traversing the parent node of curr node
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        vector<int>ans;
        //Whatever remains in the queue will be our answer 
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};