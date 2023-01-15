class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndex = 0;
        int currFuel=0;
        int gasSum = accumulate(begin(gas),end(gas),0);
        int costSum = accumulate(begin(cost),end(cost),0);
        if(gasSum < costSum) return -1; //in this case circular path can't exist
        for(int i=0;i<size(gas);i++){
            currFuel += gas[i]-cost[i];
            if(currFuel < 0){
                startIndex = i+1;
                currFuel=0;
            }
        }
        return startIndex;
    }
};