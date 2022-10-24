class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        while(i<n){
            if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) 
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};