class Solution {
public:
    int calculateMaxHeight(int index, int heightDifference, vector<int>& rods, vector<vector<int>>& dp){
    int n = rods.size();
    // Base case: reached the end of rods
    if (index >= n) {
        if (heightDifference == 5000) return 0;  // Balanced billboard with a height difference of 5000
        return INT_MIN; 
    }
    // Check if the result is already computed
    if (dp[index][heightDifference] != INT_MIN) return dp[index][heightDifference];
    // Exclude the current rod
    int option1 = calculateMaxHeight(index + 1, heightDifference, rods, dp);
    // Use it as a positive difference
    int option2 = calculateMaxHeight(index + 1, heightDifference - rods[index], rods, dp);
    // Use it as a negative difference
    int option3 = rods[index] + calculateMaxHeight(index + 1, heightDifference + rods[index], rods, dp);
    // Store the maximum result in the DP table
    return dp[index][heightDifference] = max({ option1, option2, option3 });
}
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int>(10001, INT_MIN));
        return calculateMaxHeight(0, 5000, rods, dp);  // Start recursion from the beginning with initial height difference of 5000
    }
};