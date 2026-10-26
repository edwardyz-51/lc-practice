class WordDictionary {
    struct TrieNode{
        bool word = false;
        TrieNode * children[26] = {nullptr};
    };
public:
    TrieNode * root;
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        size_t i(0uz);
        TrieNode* cur = root;
        while (i < word.size()){
            int c = word[i++]-'a';
            if (!cur->children[c]) cur->children[c]=new TrieNode;
            cur = cur->children[c];
            
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(0,word,root);
    }

    bool dfs(int i, const string& word, TrieNode* node) {
        if (!node) return false;
        if (i == word.length()) return node->word;
        char c = word[i];
        if (c == '.') {
            for (int k = 0; k < 26; k++) {
                if (node->children[k] && dfs(i + 1,word, node->children[k])) { //try all letters
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            return dfs(i + 1,word, node->children[idx]);
        }
    }
};
