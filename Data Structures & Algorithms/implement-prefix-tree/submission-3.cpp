class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord=false;
};


class PrefixTree {
    TrieNode* root;
    TrieNode* find(string word){
        TrieNode*cur = root;
        for (char c:word){
            if (cur->children.find(c)==cur->children.end()){
                return nullptr;
            }
            cur = cur->children[c];
        }
        return cur;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c)==cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur=cur->children[c];
        }
        cur->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* temp = find(word);
        return temp ? temp->endOfWord : false;
    }
    
    bool startsWith(string prefix) {
        return find(prefix);
    }
};
