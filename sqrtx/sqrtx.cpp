class Solution {
public:
    //O(n) solution
    // int mySqrt(int x) {
    //     for(int i=0;i<=x;i++){
    //         if(i*i >x) 
    //             return i-1;
    //     }
    //     return -1;
    // }
   
   //As below approach uses binary search it's complexity is O(logn) 
    int mySqrt(int x){
        
        if(x==0) return 0;
        
        int s=1, e=INT_MAX ,ans = 0;
        
        while(s<=e){
            int m = s + (e - s)/2;
            if (m <= x/m) //to avoid the overflow condition
            {
                s = m + 1;
                ans = m;
            } 
            else {
                e = m-1;
            }
        }
        return ans;
    }
    
};