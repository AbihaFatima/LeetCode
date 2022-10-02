class Solution {
public:
    //TC:O(N)
    //SC:O(1)
    bool canJump(vector<int>& nums) {
        int i=0;
        int jumpIndex=0;
        int n = nums.size();
        while(i<n){
            if(i>jumpIndex) return false;
            jumpIndex = max(jumpIndex, nums[i]+i);
            i++;
        }
        return true;
    }
};