class Solution {
public:
    //Approach - sort the intervals and increment the ans if the prev. end is greater than curr. end of interval
    //TC:O(NlogN) SC:O(1)
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(begin(in),end(in));
        int count=0;
        int prevEnd = in[0][1];
        for(int i=1;i<size(in);i++){
            if(prevEnd > in[i][0]){
                count++;
                prevEnd = min(prevEnd,in[i][1]);
            }
            else prevEnd = in[i][1];
        }
        return count;
    }
};