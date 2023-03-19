class LRUCache {
public:
    class node{
        public:
        int key,val;
        node *next,*prev;
        node(int k,int v){
            key=k;
            val=v;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cacheCapacity;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        cacheCapacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node *newN){
        node *temp = head->next;
        newN->next=temp;
        newN->prev=head;
        head->next=newN;
        temp->prev=newN;
    }
    
    void deleteNode(node *delN){
        node *delPrev = delN->prev;
        node *delNext = delN->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *ansN = mp[key];
            int ans=ansN->val;
            mp.erase(key);
            deleteNode(ansN);
            addNode(ansN);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==cacheCapacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */