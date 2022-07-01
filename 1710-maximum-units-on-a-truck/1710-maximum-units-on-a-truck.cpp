/*
Time Complexity: O(NlogN) - (Sort & Choose Greedily)
Space Complexity: O(1)
*/
class Solution {
public:
    //comparator func for(in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units )
    bool static compare(vector<int>&a ,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int maxUnits=0;
        for(int i=0;i<boxTypes.size();i++){
            //choose minimum boxes from available boxes and capacity left
            int curr = min(boxTypes[i][0],truckSize);
            //adding units in ans
            maxUnits += (curr*boxTypes[i][1]);
            //reduce the capacity
            truckSize -= curr;
            //If capacity is full then break
            if(truckSize <= 0) break;
        }
        return maxUnits;
    }
};