class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //make a min heap
        priority_queue<int, vector<int>, greater<int>> mp;
        for(int i :  nums){
            mp.push(i);
            if(mp.size() > k){
                mp.pop();
            }
        }
        return mp.top();
    }
};