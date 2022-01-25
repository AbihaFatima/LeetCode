class Solution {
public:
    //Brute-force approach that uses sorting and so the time complexity would be O(NlogN)
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int n= nums.size()-1;
    //     return nums[n-k+1];
    // }
    
    //We can optimize the time complexity from O(nlogn) to O(nlogk) using min heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > min_heap;
        for(int i=0;i<nums.size();i++){
            min_heap.push(nums[i]);
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};