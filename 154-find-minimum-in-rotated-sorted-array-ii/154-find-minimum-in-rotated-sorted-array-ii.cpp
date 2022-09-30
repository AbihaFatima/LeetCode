class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1, mid;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[low] < nums[high]) return nums[low];
            else if(nums[mid] > nums[high]) low=mid+1; 
            else if(nums[mid] < nums[low]){
                high = mid;
                low++;
            }
            else high--;
        }
        return nums[low];
    }
};