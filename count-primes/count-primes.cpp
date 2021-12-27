class Solution {
public:
    //Sieve of Eratosthenes Approach
    //We are marking all the elements from 0-n as true (prime)
    //and then checking for prime number and marking the multiples of prime numbers as false
    // TimeComplexity : (n/2 + n/3 + n/5 + n/7....)
    //                  n (1/2 + 1/3 + 1/5 +......)
    //                 O( n*log(log n) )
    int countPrimes(int n) {
        int counter = 0;
        vector<bool> prime(n+1,true);
        prime[0] = prime [1] = false;
        
        for(int i=2;i<n;i++){
            if(prime[i]){
                counter++;
            }
            
            for(int j=i*2; j<n ; j=j+i){
                prime[j] = false;
            }
            
        }
        return counter;
    }
};