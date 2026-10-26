class PrefixTree {
    struct node{
        node * children[26] = {nullptr};
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
            size_t c = word[i++]-'a';
            if (!cur->children[c]) 
                cur->children[c] = new node;
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        size_t i(0uz);
        node*cur = root;
        while (i < word.size() && cur) cur = cur->children[word[i++]-'a'];
        return cur && cur->word;
    }
    
    bool startsWith(string prefix) {
        size_t i(0uz);
        node*cur = root;
        while (i < prefix.size() && cur) cur = cur->children[prefix[i++]-'a'];
        return cur;
    }
};
