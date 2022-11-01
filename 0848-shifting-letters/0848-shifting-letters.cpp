class Solution {
public:
    /*
    s="abc" shifts = 3,5,9
    s[0] = shifted 3+5+9 times in total (a->r)
    s[1] = shifted 5+9 times (b->p)
    s[2] = shifted 9 times (c->l)
    */
    string shiftingLetters(string s, vector<int>& shifts) {
        long sum = 0;
        for(int i=shifts.size()-1;i>=0;i--){
            sum += shifts[i];
            s[i] = ((s[i]-'a')+sum)%26 + 'a';
        }
        return s;
    }
};