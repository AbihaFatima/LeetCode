class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto it: tasks){
            mp[it]++;
        }
        priority_queue<int>pq;
        int res=0;
        for(auto it: mp){
            pq.push(it.second); //pushing the freq of tasks in max-heap
        }
        while(!pq.empty()){
            int time=0;
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto i: temp){
                if(i>0) pq.push(i);
            }
            res += pq.empty() ? time : n+1;
        }
        return res;
    }
};