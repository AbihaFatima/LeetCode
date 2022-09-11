class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> engineer;
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i=0;i<n;i++){
            engineer.push_back({efficiency[i], speed[i]});
        }
        
        sort(engineer.begin(),engineer.end());
        long sum=0,ans=0;
        for(int i=n-1;i>=0;i--){
            sum += engineer[i].second;
            minh.push(engineer[i].second);
            
            if(minh.size() > k){
                sum -= minh.top();
                minh.pop();
            }
            ans = max(ans, sum*engineer[i].first);
        }
        return ans % (int)(1e9+7);
    }
};