class Solution {
public:
    //Brute-force solution
    //Time Complexity: O(N)
    //Space Complexity: O(N)
    // int kthFactor(int n, int k) {
    //     if(k==1)    return 1;
    //     vector<int>factors;
    //     for(int i=1;i<=n;i++){
    //         if(n%i==0) factors.push_back(i);
    //     }
    //     if(k>factors.size()) return -1;
    //     else
    //         return factors[k-1];
    // }
    
    //Optimal Solution
    //TC:O(n/2) and SC:O(1)
    int kthFactor(int n, int k) {
        int i=1;
        for(i=1;i<=n/2;i++){
            if(n%i==0) k--;
            if(k==0) return i;
        }
        if(k==1) return n; //for prime numbers as only 2 factors are present
        return -1;
    }
    
};