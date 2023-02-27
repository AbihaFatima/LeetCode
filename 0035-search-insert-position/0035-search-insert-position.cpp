class Solution {
public:
    //Binary Search O(log n) 
    //Finding floor in sorted array
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums[nums.size()-1]) return nums.size();
        if(target < nums[0]) return 0;
        int low=0,mid,high=size(nums)-1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid-1;
        }
        return low;
    }
};