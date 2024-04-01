class Solution {
public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Ensuring nums1 is smaller for efficiency
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int partition1 = lo + (hi - lo) / 2; // Partition index in nums1
            int partition2 = (n1 + n2 + 1) / 2 - partition1; // Corresponding partition index in nums2
            
            int l1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1]; // Element on left of partition in nums1
            int l2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1]; // Element on left of partition in nums2
            
            int r1 = (partition1 == n1) ? INT_MAX : nums1[partition1]; // Element on right of partition in nums1
            int r2 = (partition2 == n2) ? INT_MAX : nums2[partition2]; // Element on right of partition in nums2
            
            // Checking partition correctness
            if (l1 > r2)
                hi = partition1 - 1; // Move left in nums1
            else if (l2 > r1)
                lo = partition1 + 1; // Move right in nums1
            else {
                if ((n1 + n2) % 2) // Odd total elements in merged array
                    return static_cast<double>(std::max(l1, l2)); // Single median element from right part
                else // Even total elements in merged array
                    return (static_cast<double>(std::max(l1, l2)) + std::min(r1, r2)) / 2; // Median of two middle elements
            }
        }
        
        return -1.0; // Default return value indicating error
    }
};