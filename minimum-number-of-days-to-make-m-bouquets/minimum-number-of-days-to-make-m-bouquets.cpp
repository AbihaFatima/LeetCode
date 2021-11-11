class Solution {
public:
    //Time Complexity for binary search O(logN) or O(log(INT_MAX)) + check func O(N)
    //Total Complexity O(N log(INT_MAX))
    bool check(vector<int>&a, int m, int k,int mid){
        int total = 0, consecutiveCount = 0;
        for(int i = 0; i<a.size();i++){
            if(a[i] <= mid){
                consecutiveCount++;
                if(consecutiveCount == k){
                    total++;
                    consecutiveCount = 0;
                }
            }
            
            else
                consecutiveCount = 0;
        }
        
        if(total >= m)
            return true;
        
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0, e = 1e9, ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(bloomDay, m, k, mid)){
                ans = mid;
                e = mid -1;
            }
            else
                s = mid +1;
        }
        
        return ans;
    }
};