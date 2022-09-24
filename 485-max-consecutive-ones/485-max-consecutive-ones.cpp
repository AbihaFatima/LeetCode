class Solution {
public:
    //TimeComplexity = O(N)
    //SpaceComlexity = O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0, maximum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maximum = max(ones,maximum);
                ones=0;
            }
            else
                ones++;
        }
        return max(maximum,ones);
    }
};