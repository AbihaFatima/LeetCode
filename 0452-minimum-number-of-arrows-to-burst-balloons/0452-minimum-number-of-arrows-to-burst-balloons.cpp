class Solution {
public:
    //Similar to non-overlapping intervals
    //Returning the differnce between total intervals and merged intervals;
    int findMinArrowShots(vector<vector<int>>& in) {
        sort(begin(in),end(in));
        int count=0;
        int prevEnd=in[0][1];
        for(int i=1;i<size(in);i++){
            if(prevEnd >= in[i][0]){
                count++;
                prevEnd = min(prevEnd, in[i][1]);
            }
            else prevEnd = in[i][1];
        }
        return size(in)-count;
    }
};