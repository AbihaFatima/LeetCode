class Solution {
public:
    /*
    [0,1,2,1]
    
    [0,10,5,2] 
     ^      ^
    */
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