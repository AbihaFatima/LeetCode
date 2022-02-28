class Solution {
public:
    //BFS Approach to check bipartition
    //Time Complexity: O(N+E)
    //Space Complexity: O(N+E)
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int>q;
        vector<int>colorArr(n,-1);
        for(int i=0;i<n;i++){
            if(colorArr[i]==-1){
            q.push(i);
            colorArr[i]=0;
            while(!q.empty()){
                int it = q.front();
                q.pop();
                for(auto its : graph[it]){
                    if(colorArr[its] == colorArr[it]) return false;
                    if(colorArr[its] == -1){
                        colorArr[its] = 1-colorArr[it];
                        q.push(its);
                    }
                }
            }
         }
        }
        return true;
    }
};