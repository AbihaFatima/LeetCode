class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=size(nums);
        int start=0,mid,end=n-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(target==nums[mid]) return mid;
            else if(nums[start]<=nums[mid]){
                if(target>=nums[start] and target<=nums[mid]) end=mid-1;
                else start=mid+1;
            }
            else if(nums[mid]<=nums[end]){
                if(target>=nums[mid] and target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }
};