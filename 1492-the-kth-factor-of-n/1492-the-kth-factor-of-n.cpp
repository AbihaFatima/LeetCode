class Solution {
public:
    //Brute-force solution
    //Time Complexity: O(N)
    //Space Complexity: O(N)
    int kthFactor(int n, int k) {
        if(k==1)    return 1;
        vector<int>factors;
        for(int i=1;i<=n;i++){
            if(n%i==0) factors.push_back(i);
        }
        if(k>factors.size()) return -1;
        else
            return factors[k-1];
    }
};