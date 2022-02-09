class Solution {
public:
    //Two Pointer Approach
    //Time Complexity: O(NlogN)
    //Space Complexity: O(1)
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        //Maintaining two pointers one initialized at index 0 and other at index 1
        sort(nums.begin(),nums.end());
		int fast=1;
		int slow=0;
		int count=0;
		while(slow<nums.size() && fast<nums.size()){
			if(nums[fast]-nums[slow]==k){
				count++;
				fast++;
				slow++;
				while(fast<nums.size() && nums[fast]==nums[fast-1]){
					fast++;
				}
			}
			else if(nums[fast]-nums[slow]>k){
				slow++;  
				if(fast-slow==0){
					fast++;}
			}
			else{      
				fast++;
			}         
		}
		return count;
    }
};