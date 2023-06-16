class Solution {
public:
    long long mod = 1000000007;
    std::vector<std::vector<long long>> table;
    
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        table.resize(n, std::vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            table[i][0] = table[i][i] = 1;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        std::vector<int> res;
        for (int i : nums)
            res.push_back(i);
            
        return (int)((helper(res) - 1) % mod);
    }
    
    long long helper(std::vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 1;
        std::vector<int> lst;
        std::vector<int> rst;
        for (int i = 1; i < n; i++) {
            int element = arr[i];
            if (element < arr[0]) lst.push_back(element);
            else rst.push_back(element);
        }
        long long left = helper(lst) % mod;
        long long right = helper(rst) % mod;
        return (((left * right) % mod) * table[n - 1][lst.size()]) % mod;
    }
};