class Solution {
public:
//(Space Optimized DP)
// TC: O(k), SC: O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int front = 0, rear = 0;
        
        for(int i=0;i<k; i++)
            front += cardPoints[i];
        
        int maxScore = front, currentScore;
        
        for(int i=k-1; i>=0; i--){
            front -= cardPoints[i];
            rear += cardPoints[n-(k-i)];
            currentScore = front+rear;
            maxScore = max(currentScore, maxScore);
        }
        return maxScore;
    }
};