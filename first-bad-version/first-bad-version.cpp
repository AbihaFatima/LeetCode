// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    //Binary Search for 1st bad version - O(logn)
    int firstBadVersion(int n) {
       int low = 0, high = n, mid;
        while(high-low>1){
            int mid=low+(high-low)/2;
            if(isBadVersion(mid))
            {
                high=mid;
            }
            else{
                low=mid;
        }
        }
        return high;
    }
};