class Solution {
public:
    //TimeComplexity : O(N)
    //Space Complexity: O(K)
    int subarraysDivByK(vector<int>& A, int K) {
        int len = A.size();
        unordered_map<int, int> ht;

        int accu_sum = 0;
        int count = 0;
        int modulo;
        ht[0] = 1;
        for (int i = 0; i < len; i ++) {
            accu_sum += A[i];
            modulo = accu_sum % K;
            if (modulo < 0)
                modulo += K;
            if (ht.find(modulo) == ht.end()) {
                ht[modulo] = 0;
            }
            count += ht[modulo];
            ht[modulo] ++;
        }
        return count;
        }
};