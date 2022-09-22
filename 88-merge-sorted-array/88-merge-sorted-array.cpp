class Solution {
public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         //Reverse Sorting Approach
//         //We initialize k=m+n-1 as that will be the last location of nums1.
//         int i=m-1;
//         int j=n-1;
//         int k=m+n-1;
        
//         while(i>=0&&j>=0)
//         {
//             if(nums1[i]>nums2[j])//keep checking for the greater element of the two arrays(i=m-1,j=n-1) and insert the values.
//             {
//                 nums1[k]=nums1[i];
//                 i--;
//                 k--;
//             }
//             else
//             {
//                 nums1[k]=nums2[j];
//                 j--;
//                 k--;
//             }
//         }
//         while(i>=0)
//             nums1[k--]=nums1[i--];
//         while(j>=0)
//             nums1[k--]=nums2[j--];
        
//     }
    
    //Brute-force approach - TC: O(NlogN) SC:O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m] = nums2[i];
            m++;
        }
        sort(nums1.begin(),nums1.end());
    }
};