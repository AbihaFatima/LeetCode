class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int count = 0;
        unordered_map<int,int>map;
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum == k){
                count += 1;
            }
            if(map.find(currSum-k) != map.end()){
                count += map[currSum-k];
            }
            map[currSum] += 1;
        }
        return count;
    }
};