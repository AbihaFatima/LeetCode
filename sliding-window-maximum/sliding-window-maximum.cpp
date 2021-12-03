class Solution {
public:
//Brute force would take O(n^2) time complexity
    
//This is the most optimise solution
//O(N) time complexity and O(k) space complexity (for deque data structure which at max stores k elements)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> d;
        vector<int>res;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(!d.empty() && d.front() == (i-k)){ //for deque to be not empty and i-k is it should not be out of bound 
                d.pop_front(); //pop the previous elements (out of bound elements)
            }
            
            while(!d.empty() && nums[d.back()] <= nums[i]){ // remove all the smaller elements before
                d.pop_back();
            }
            
            d.push_back(i); //once smaller and out of bound index is removed the current index can be pushed into deque
            
            if(i >= k-1){ //i.e the first subarray starts from i=2 i.e k-1
                res.push_back(nums[d.front()]);
            }
        }
        
        return res;
    }
};