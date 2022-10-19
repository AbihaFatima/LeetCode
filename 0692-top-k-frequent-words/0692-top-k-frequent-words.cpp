class Solution {
public:
    //Storing the frequency of words in a hashmap
    //Then making a min-heap and push the pair<freq,word> in the heap
    //We will just pop if if heap size is greater than k
    //TC: O(N) + O(NlogK) [for hashmap + for pq that is O(K) each time]
    //SC: O(K)+O(K) (for hashmap and pq)
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        priority_queue<pair<int,string>> pq; //this actually defines a max heap, but later with negative flipping operation, it behaves like a min-heap :D
        for(auto it: mp){
            pq.push({-it.second,it.first});
            while(pq.size() > k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};