class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=size(nums);
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            //if array is sorted
            if(nums[low]<nums[high]) return nums[low];
            //check if left half is sorted, move towards right
            if(nums[mid]>nums[high]) low=mid+1;
            //check if right half is sorted, move towards left
            else if(nums[mid]<nums[high]) high=mid;
            //for handling duplicate values
            //eg. 6,1,1,1,2,3,4,5 (nums[mid]==nums[high] or nums[mid]==low)
            else high--;
        }
        return nums[high];
    }
};