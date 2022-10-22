class Solution {
public:
    //Approach: Sliding Window 
    string minWindow(string s, string t){
        unordered_map<char,int>letters;
        //Store the counts of characters in 't'
        for(auto c:t) letters[c]++;
        
        int count=0,min_len=INT_MAX,min_start=0,low=0;
        
        //Iterating over s
        for(int high=0;high<s.size();high++){
            // If this character is required, then update count (Add it to the window)
            if(letters[s[high]]>0) count++;
            // Reduce the count for this character (since we have added this to the window)
            letters[s[high]]--;
            // If we have all the valid characters, update substring
            if(count==t.length()){
                //  This makes sure that letters[s[low]] is not negative
            //  Because if it is negative, than that means we have more s[low]s than required.
            //  So we have to remove such characters
                while(low<high && letters[s[low]]<0){
                    letters[s[low]]++;// Remove character from window, update count
                    low++;// Update substring window start
                }
                // Update substring
                if(min_len>high-low+1){
                    min_start = low;
                    min_len = high-low+1;
                }
            }
        }
        // No substring satisfies 't'
        if(min_len == INT_MAX) return "";
        // Return the best substring
        return s.substr(min_start,min_len);
    }
};