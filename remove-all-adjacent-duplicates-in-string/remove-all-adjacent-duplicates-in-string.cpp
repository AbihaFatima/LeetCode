class Solution {
public:
    string removeDuplicates(string s) {
    
    stack<char> st; // Store the string without duplicate elements
     
    int i = 0;// Store the index of str
     
    // Traverse the string s
    while (i < s.length())
    {
        if (st.empty() || s[i] != st.top())
        // Checks if stack is empty or top of the stack is not equal to current character
        {
            st.push(s[i]);
            i++;
        }
        else
        // If top element of the stack is equal to the current character
        {
            st.pop();
            i++;
        }
    }
      
    // If stack is not Empty
    string short_string = "";
    if(!st.empty())
    {
        while (!st.empty())
        {
            short_string = st.top() +
                           short_string;
            st.pop();
        }
    }
    return short_string;
    }
};