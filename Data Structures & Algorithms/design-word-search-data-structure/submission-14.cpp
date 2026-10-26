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

    bool dfs(size_t i, const string& word, TrieNode* node) {
        if (i == word.length()) return node->word;
        if (word[i] == '.') {
            for (size_t k(0uz); k < 26; k++) 
                if (node->children[k] && dfs(i + 1,word, node->children[k])) return true;
            return false;
        } else return node->children[word[i]  - 'a'] ? dfs(i + 1,word, node->children[word[i] - 'a']) : false;
    }
};
