class NumArray {
private:
    vector<int>pSum;
public:
    NumArray(vector<int>& nums) {
        pSum.clear(); //as pSum is inialized as global variable inorder to remove garbage value we are clearing the array first
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0) pSum.push_back(nums[i]);
            else
                pSum.push_back(nums[i]+pSum[i-1]);
        }
    }
    /*
Example:
ar = [-2, 0, 3, -5, 2, -1]
range = [0, 2], [2, 5]

Prefix Sums Array = [-2,-2,1,-4,-2,-3]

Output:
For query 1, left == 0, return prefix sum at index right. Print pref[2] = 1
For query 2, left != 0, return pref[right] - pref[left - 1]. Print pref[5] - pref[1] = -1
    */
    int sumRange(int left, int right) {
        if(left==0) return pSum[right];
        else
            return pSum[right]-pSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */