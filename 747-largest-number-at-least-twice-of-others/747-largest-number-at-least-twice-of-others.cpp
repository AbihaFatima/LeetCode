class Solution {
public:
    //Approach : Finding Max number in the array 
    //and as the question says maxNum should be atleast twice which depicts that 
    //maxNum >= 2*every_other_element 
    int dominantIndex(vector<int>& nums) {
        int maxNum = nums[0];
        int maxIndex = 0;
        int n = nums.size();
        //Iterating over the loop to find maxNum
        for(int i=1;i<n;i++){
            if(maxNum < nums[i]){
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        //Comparing MaxNum with all other elements of array except self
        for(int i=0;i<n;i++){
            if(maxIndex == i) continue;
            if(maxNum < 2*nums[i]){
                return -1;
            }
        }
        return maxIndex; //Returning the Index of the maximum element
    }
};