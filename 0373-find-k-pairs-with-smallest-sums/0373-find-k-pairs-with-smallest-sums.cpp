class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;  
        int n = nums1.size();        
        int m = nums2.size();
        if (n == 0 || m == 0) return result;
        priority_queue<tuple<int, int, int>> pq;  // Max-heap to store pairs based on sum
        pq.push({-nums1[0] - nums2[0], 0, 0});    
        while (!pq.empty() && result.size() < k) {
            auto topPair = pq.top();           // Get the top pair from the max-heap
            int i = get<1>(topPair);           // Index i of nums1
            int j = get<2>(topPair);           // Index j of nums2
            pq.pop();                          // Pop the top pair
            result.push_back({nums1[i], nums2[j]});  // Add the pair to the result
            if (j == 0 && i + 1 < n) {
                pq.push({-nums1[i + 1] - nums2[j], i + 1, j});  // Push the pair (i+1, j) to the max-heap
            }
            if (i < n && j + 1 < m) {
                pq.push({-nums1[i] - nums2[j + 1], i, j + 1});  // Push the pair (i, j+1) to the max-heap
            }
        }
        return result; 
    }
};
