class Solution {
public:
    //Brute-force solution using max-heap 
    //TC: O(N * N * log K)
    //SC: O(K)
    int kthSmallest(vector<vector<int>>& m, int k) {
        priority_queue<int>maxh;
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxh.push(m[i][j]);
                while(maxh.size()>k){
                    maxh.pop();
                }
            }
        }
        return maxh.top();
    }
};