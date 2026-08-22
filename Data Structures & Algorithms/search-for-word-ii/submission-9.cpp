class Solution {
struct Node {
        bool isEnd = false;
        bool isUsed = false;
        string current;
        Node* child[26];
        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };
void add(string s, int index, Node* root){
    if (index == s.length()){
        root->isEnd=true;
        root->current = s;
        return;
    } 
    int c = s[index] - 'a';
    if (!(root->child[c])) root->child[c] = new Node();
    add(s,index+1,root->child[c]);
}
Node* root = new Node();
void dfs(int row, int col, vector<vector<char>>& board, Node* node, vector<string>&ans){
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
            || board[row][col] == '#' || !node->child[board[row][col]-'a']) return;
        char c = board[row][col];
        board[row][col] = '#';
        Node* next = node->child[c-'a'];
        if (next && next->isEnd && !next->isUsed){
            next->isUsed=true;
            ans.push_back(next->current);
        }
        dfs(row+1,col,board,next,ans);
        dfs(row-1,col,board,next,ans);
        dfs(row,col+1,board,next,ans);
        dfs(row,col-1,board,next,ans);
        board[row][col]=c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        for (string s : words) add(s,0,root);
        for (int row = 0; row < board.size(); ++row){
            for (int col = 0; col < board[0].size(); ++col){
                if (root->child[board[row][col]-'a']){
                    dfs(row,col,board,root,ans);
                    if (ans.size()==words.size()) return ans;
                }
            }
        }
        return ans;
    }  
};
