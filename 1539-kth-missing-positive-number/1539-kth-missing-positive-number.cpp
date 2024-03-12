class Solution {
public:
    //BinarySearch- TC:O(logN) SC:O(N)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid = (low+high)/2; 
            //Number of missing element at mid arr[mid]-(mid+1)
            if(arr[mid] - (mid+1) < k) low=mid+1;
            else high=mid-1;
        }
        return low+k;
    }
};