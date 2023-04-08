/*
//Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
TC: O(V+E) for DFS
SC: O(V) for visited array
*/
class Solution {
    void dfs(Node* node, vector<Node*>&vis,Node* copy)
    {
        vis[copy->val] = copy;
        for(auto it : node->neighbors){
            if(vis[it->val]==NULL){
                Node *newNode = new Node(it->val);
                (copy->neighbors).push_back(newNode);
                dfs(it, vis, newNode);
            }
            else{
                (copy->neighbors).push_back(vis[it->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL) return NULL;
        Node *copy = new Node(node->val);
        vector<Node*>vis(1000,NULL);
        dfs(node,vis,copy);
        return copy;
    }
};