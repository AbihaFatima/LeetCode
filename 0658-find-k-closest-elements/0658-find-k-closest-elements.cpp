class Solution {
public:
    //Time Complexity : O((N+K)logK) Space Complexity : O(K)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int,int>> maxh;
        for(int i=0;i<n;i++){
            maxh.push({abs(x-arr[i]), arr[i]});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size()!=0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};