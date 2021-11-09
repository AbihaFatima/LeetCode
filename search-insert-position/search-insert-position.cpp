class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums[nums.size()-1])
            return nums.size();
        if(target < nums[0])
            return 0;
        int mid;
        int low = 0;
        int high = nums.size();
        while(low < high)
        {
            mid = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid-1] < target && nums[mid] > target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return 0;
    }
};