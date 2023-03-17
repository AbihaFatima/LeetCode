/*
 Algorithm    |  Time Complexity  |   Space Complexity
  Insert      |      O(N)         |         O(N)
  Search      |      O(N)         |         O(1)
  startWith   |      O(N)         |         O(1)
*/
#define MAX_NODES 10000
class Trie {
    //Structure of each node of a trie
    struct Trienode {
        char val;
        int count;
        int endsHere;
        Trienode *child[26]; 
    };
    Trienode *root;
    
    //Making all nodes pointing to NULL initially
    Trienode *getNode(int index)
    {
        Trienode *newnode = new Trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endsHere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
public:
    Trie(){
        root = getNode('/'-'a');
    }
    
    //Inserts a word into trie
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(index);
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->endsHere +=1;
    }
    
    //Returns if the word is in trie or not
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    //Returns if there is word present in trie which starts with given prefix
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i=0;prefix[i]!='\0';++i)
        {
            index = prefix[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);//it returns true if count of current node is greater than zero, means there exists one or more string with the given prefix
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */