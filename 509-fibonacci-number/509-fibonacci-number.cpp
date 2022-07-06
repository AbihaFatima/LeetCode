class Solution {
public:
	// //Brute-force approach
	// int fib(int n) {
	// if(n==0 || n==1){
	// 	return n;
	// }
	// return fib(n-1) + fib(n-2);
	// }
    
    /*
    -----------(Using two variables)----------
    Time Complexity - O(N)
    Space Complexity - O(1)
    */
    int fib(int N){
        if(N < 2){
			return N;
		}
		int x = 0;
		int y = 1;
		for(int i = 2; i <= N; i++){
			y = x + y;
			x = y - x;
		}
		return y;
    }
};