class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        vector<vector<int>> res;
        int j=0;
        //non-overlapping intervals before newInterval
        while(j<in.size() and in[j][1] < newIn[0]) res.push_back(in[j++]);
        //for overlapping intervals
        while(j<in.size() and in[j][0] <= newIn[1]){
            newIn[0] = min(in[j][0],newIn[0]);
            newIn[1] = max(in[j][1],newIn[1]);
            j++;
        }
        res.push_back(newIn);
        //for intervals after overlapping intervals
        while(j<in.size()) res.push_back(in[j++]);
        return res;
    }
};