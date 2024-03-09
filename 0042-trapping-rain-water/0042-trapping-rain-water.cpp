class Solution {
public:
    //Two Pointer Approach
    //TC:O(N) SC:O(1)
    int trap(vector<int>& ht) {
        int leftMax=INT_MIN, rightMax=INT_MIN;
        int n=ht.size();
        int res=0;
        int left=0,right=n-1;
        while(left<=right){
            if(ht[left] <= ht[right]){
                leftMax = max(ht[left],leftMax);
                res += (leftMax-ht[left]);
                left++;
            }
            else{
                rightMax = max(rightMax, ht[right]);
                res += (rightMax - ht[right]);
                right--;
            }
        }
        return res;
    }
};