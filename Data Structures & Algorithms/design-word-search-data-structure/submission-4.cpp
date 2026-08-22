#include <unordered_map>
#include <string>

class WordDictionary {
private:
    struct Node {
        bool isWord = false;
        std::unordered_map<char, Node*> child; // only store existing edges
    };

    Node* root;

    bool dfs(const std::string& word, int i, Node* node) {
        if (!node) return false;
        if (i == (int)word.size()) return node->isWord;

        char c = word[i];
        if (c == '.') {
            for (auto& [ch, nxt] : node->child) {
                if (dfs(word, i + 1, nxt)) return true;
            }
            return false;
        } else {
            auto it = node->child.find(c);
            if (it == node->child.end()) return false;
            return dfs(word, i + 1, it->second);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(std::string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->child.count(c)) cur->child[c] = new Node();
            cur = cur->child[c];
        }
        cur->isWord = true;
    }

    bool search(std::string word) {
        return dfs(word, 0, root);
    }
};
