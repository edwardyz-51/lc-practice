class Trie {
public:
    struct Node{
        Node* children[26] = {nullptr};
        string word;
    };
    Node* root;
    Trie(){root = new Node;}
    void insert(string& word) {
        size_t i(0uz);
        Node*cur = root;
        while (i < word.size()){
            size_t c = word[i++]-'a';
            if (!cur->children[c]) 
                cur->children[c] = new Node;
            cur = cur->children[c];
        }
        cur->word = word;
    }
};
class Solution {
    size_t N, M;
    static constexpr int dir[] = {0,1,0,-1,0};
    vector<string> ans;
    vector<vector<char>>board;
    void dfs(size_t row, size_t col, Trie::Node* cur){
        if (!cur->word.empty()) ans.push_back(cur->word), cur->word.clear();
        char prev = board[row][col];
        board[row][col]='#';
        for (size_t i(0uz); i < 4; ++i){
            int nr = row + dir[i], nc = col + dir[i+1];
            if (nr < 0 || nc < 0 || nr == N || nc == M || board[nr][nc] == '#') continue;
            if (cur->children[board[nr][nc]-'a']) dfs(nr,nc,cur->children[board[nr][nc]-'a']);
        }
        board[row][col] = prev;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        Trie trie;
        for (string& word : words) trie.insert(word);
        Trie::Node * root = trie.root;
        N = board.size(), M = board.front().size();
        for (size_t row(0uz); row < N; ++row)
            for (size_t col(0uz); col < M; ++col)
                if (root->children[board[row][col]-'a']) 
                dfs(row,col,root->children[board[row][col]-'a']);
        return ans;
        
    }
};
