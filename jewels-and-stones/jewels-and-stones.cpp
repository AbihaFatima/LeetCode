class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_map<int, int> q; //Creating a hashmap and adding all values of jewels as `key` in the map
        for(char a:jewels){
            q[a]++;
        }
        
        //Now we will check if each character of stones is a key in map or not
        int count=0;
        for(char a:stones){
            if(q.find(a)!=q.end()){
                count++;
            }
        }
        return count;
    }
    //Total time complexity is  O(max(jewels, stones))
};