class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n = nums.size();
        int low=0, high=n-1,mid;
        //To find last occurance by shifting the search window towards left
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            if(nums[mid] == target){
                ans[0] = mid;
                high = mid-1;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
        }
        low=0;high=n-1;
        //To find last occurance by shifting the search window towards right
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            if(nums[mid] == target){
                ans[1] = mid;
                low = mid+1; 
            }
            if(nums[mid] < target){
                low = mid+1;
            }
        }
        return ans;
    }
};