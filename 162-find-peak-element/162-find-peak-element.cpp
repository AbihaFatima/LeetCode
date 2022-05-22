class Solution {
public:
    /*
    As given in the question it requires to be solved in O(log n) time which leads us to think a binary search solution. TC:O(logn) SC:O(1)
    */
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //Base cases when number of elements are 1 and 2 respectively.
        if(n==1) return 0; //returning the first index 
        if(n==2) return nums[0]>nums[1]?0:1;
        
        //Binary Search
        int low = 1,high=n-2;
        while(low<=high){
            int mid = high+(low-high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid+1]>nums[mid]) low=mid+1;
            else if(nums[mid-1]>=nums[mid]) high=mid-1;
        }
        //Base cases for first and last element
        if(nums[n-1]>nums[n-2]) return n-1;
        if(nums[0]>nums[1]) return 0;
        else
            return -1;
    }
};