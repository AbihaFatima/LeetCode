class Solution {
public:
    //Time Complexity : O(NlogK)+O(KlogK) ~ O((N+K)logK) 
    //Space Complexity : O(K)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int,int>> maxh;
        // making a max-heap of absolute difference and corresponding array value
        // store the difference one by one with the array value
        for(int i=0;i<n;i++){
            maxh.push({abs(x-arr[i]), arr[i]});
            if(maxh.size()>k){
                maxh.pop();//popping the element with larger difference that is when size is greater K then all the larger difference elements comes to the top.
            }
        }
        while(maxh.size()!=0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());//Sorting the answer in asc. order
        return ans;
    }
};