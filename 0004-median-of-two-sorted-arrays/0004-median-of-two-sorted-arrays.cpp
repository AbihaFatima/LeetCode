class Solution {
public:
    //Brute-force solution
    //TC: O(nlogn) SC:O(n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int n = nums2.size();
        vector<int>v=nums1;
        for(int i=0;i<n;i++) v.push_back(nums2[i]);
        sort(v.begin(),v.end());
        int m = v.size();
        int mid = m/2;
        if(m%2==0) ans = (double)(v[mid]+v[mid-1])/2;
        else ans = v[mid];
        return ans;
    }
};