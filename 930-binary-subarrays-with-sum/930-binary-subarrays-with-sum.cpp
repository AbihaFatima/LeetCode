class Solution {
public:
    //Sub-problem of subarray sum equals k
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>map;
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum == goal){
                count += 1;
            }
            if(map.find(currSum-goal) != map.end()){
                count += map[currSum-goal];
            }
            map[currSum] += 1;
        }
        return count;
    }
};