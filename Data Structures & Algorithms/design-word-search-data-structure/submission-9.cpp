class WordDictionary {
private:
    struct Node {
        bool isWord = false;
        Node* child[26] = {nullptr};
        Node() {
        }
    };

    Node* root;

    bool dfs(const string& word, int i, Node* node) {
        if (!node) return false;
        if (i == word.length()) return node->isWord;

        char c = word[i];
        if (c == '.') {
            for (int k = 0; k < 26; k++) {
                if (node->child[k] && dfs(word, i + 1, node->child[k])) { //try all letters
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            return dfs(word, i + 1, node->child[idx]);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
