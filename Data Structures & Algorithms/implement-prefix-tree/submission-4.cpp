class PrefixTree {
    struct node{
        unordered_map<char,node*>children;
        bool word = false;
    };
public:
    node * root;
    PrefixTree() {
        root = new node;
    }
    
    void insert(string word) {
        size_t i(0uz);
        node*cur = root;
        while (i < word.size()){
            if (!cur->children.contains(word[i])) 
                cur->children[word[i]] = new node;
            cur = cur->children[word[i++]];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        size_t i(0uz);
        node*cur = root;
        while (i < word.size() && cur) cur = cur->children[word[i++]];
        return cur && cur->word;
    }
    
    bool startsWith(string prefix) {
        size_t i(0uz);
        node*cur = root;
        while (i < prefix.size() && cur) cur = cur->children[prefix[i++]];
        return cur;
        
    }
};
