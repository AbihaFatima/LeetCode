class Solution {
public:
    //Binary Search Approach
    //TC: O(logN)
    //SC: O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1,mid;
        while(start<end){
            mid = start + (end-start)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] < arr[mid+1]) start=mid;
            else end = mid;
        }
        return -1;
    }
};