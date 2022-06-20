- [Detailed Approaches](https://leetcode.com/problems/remove-linked-list-elements/discuss/722528/C%2B%2B-2-solutions%3A-With-single-pointer-%2B-With-double-pointers-(Easy-to-understand)) <br>
- Recursive Approach:
```
class Solution {
public:
ListNode* removeElements(ListNode* head, int val) {
if(!head)
return head;
ListNode* newNext = removeElements(head -> next, val);
if(head -> val == val) {
return newNext;
} else {
head -> next = newNext;
return head;
}
}
};
```
​
<br>
- [Another Awesome post](https://leetcode.com/problems/remove-linked-list-elements/discuss/1572902/C%2B%2B-or-Java-or-Python-oror-Simple-Recursive-and-Iterative-Solutions-oror-NovemberChallenge)