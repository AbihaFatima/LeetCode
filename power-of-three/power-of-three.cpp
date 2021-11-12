class Solution {
public:
    //Recursive solution
    bool isPowerOfThree(int n) {
        if(n==1) return true; //Base Case
        if(n<=0) return false;
        
        if(n%3 == 0){
            return isPowerOfThree(n/3);
        }
        return false;
    }
};