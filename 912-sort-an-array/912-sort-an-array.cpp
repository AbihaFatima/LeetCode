class Solution {
public:
    //TimeCompexity : O(NlogN)
    //Using MinHeap
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>> minh;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            minh.push(nums[i]);
        }
        while(minh.size()!=0){
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};