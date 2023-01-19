class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto i: s){
            mp[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        string res="";
        
        while(pq.size()>1){
            char c1 = pq.top().second;
            int f1 = pq.top().first;
            pq.pop();
            
            char c2 = pq.top().second;
            int f2 = pq.top().first;
            pq.pop();
            
            res+=c1;
            res+=c2;
            if(--f1 > 0)
                pq.push({f1,c1});
            if(--f2 > 0)
                pq.push({f2,c2});
        }

        if(!pq.empty()){
            if(pq.top().first>1) return "";
            else{
                char lastChar=pq.top().second;
                res+=lastChar;
            }
        }
        return res;
    }
};