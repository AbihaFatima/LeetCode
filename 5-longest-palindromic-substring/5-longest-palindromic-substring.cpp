class Solution {
public:
    //Two-Pointer Approach
    //Time Complexity: O(N^2)
    //Space Complexity: O(1)
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        int start=0,end=0,max_len=0;
        //Odd Length
        for(int i=0;i<n-1;i++){
                int low=i,high=i,len=1;
                while(low>=0 && high<n){
                    if(s[low]==s[high]){
                        low--;
                        high++;
                    }
                    else
                        break;
                }
                len = high-low-1;
                if(len>max_len){
                    max_len=len;
                    start=low+1;
                    end=high-1;
                }
            }
        
        //Even Length
            for(int i=0;i<n-1;i++){
                int low=i,high=i+1,len=1;
                while(low>=0 && high<n){
                    if(s[low]==s[high]){
                        low--;
                        high++;
                    }
                    else
                        break;
                }
                len = high-low-1;
                if(len>max_len){
                    max_len=len;
                    start=low+1;
                    end=high-1;
                }
            }
        return s.substr(start,max_len);
    }
};