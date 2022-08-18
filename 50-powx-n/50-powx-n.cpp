class Solution {
public:
    //Time Complexity is O(log n)

    double myPow(double x, int n) {
        if(n==0) return 1;
        
        if(n==1) return x;
        
        double temp = myPow(x, n/2);
         temp *= temp;
        
        if(n>0)
            return (n%2==0)?temp : x*temp;//Positive value
        
        return (n%2==0)?temp : temp/x;//Negative value
       
    }
};