class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0); //for storing the frequencies of every window(substring) from s
        vector<int> phash(26,0);//for storing the frequencies of every pattern string p
        vector<int> ans;
        int window = p.size();
        int len = s.size();
        int left=0,right=0;
        if(window>len){
            return ans;
        }
        while(right<window){ //Creating 1st window, incrementing frequencies in p and s in their hashes 
            phash[p[right]-'a'] += 1;
            hash[s[right]-'a'] += 1;
            right++;
        }
        right -= 1;
        while(right<len){
            if(phash==hash){
                ans.push_back(left);
            }
            right += 1;
            if(right!=len)//Until it reaches end
            {
                hash[s[right]-'a'] += 1; //Moving foward and incremneting the frequency of char at right
            }
            hash[s[left]-'a'] -= 1;//Leaving behind the left frequency that is sliding window forward and hence decrementing left
            left += 1;
        }
        return ans;
    }
};