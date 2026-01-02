class Solution {
public:
    //tc: o(v+e) and sc: o(v+e)
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& state){
        //this node was already in path (recursion stack) n now we encountered it again so return false as it forms cycle
        if(state[node] == 1) return false;

        //this node was fully processed in prev path so, doesnt builds cycle
        if(state[node] == 2) return true;

        //if the node was unvisted i.e 0 make it visited
        state[node]=1;

        //add its neighbours to recursion stack
        for(int n : adjList[node]){
                if(!dfs(n, adjList,state)) return false; //its neighbours in future calls forms cycle
        }
        
        //after visiting its neighbours, mark the initial parent node as fully processed
        state[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>state(numCourses, 0);
        //states that we will use; 0-> unvisted, 1->currently being processed that is middle of some path, 2->fully processed without cycle detection


        //building directed adjList from bi->ai
        vector<vector<int>> adjList(numCourses);
        for(auto &e : prerequisites){
            int a = e[0], b=e[1];
            adjList[b].push_back(a);
        }

        //Starting from unvisited node doing a dfs traversal
        for(int i=0; i<numCourses; i++){
            if(state[i]==0){
                if(!dfs(i, adjList, state)) return false;
            }
        }
        return true;
    }
};