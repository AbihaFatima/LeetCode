Min Heap used here to store the head of every LL
so Time Complexity: O(N logK)
Space Complexity : O(K)
​
Min element is popped and its next element is pushed again so min heap rearranges in such a way that only minimium remains at the top. hence popped elements are transformed into Linked List