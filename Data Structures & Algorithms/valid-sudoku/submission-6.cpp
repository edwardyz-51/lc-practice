class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char>checkBox;
        for (int i = 0; i < board.size(); i++) { //vertical loop
            vector<char>checkHorizontal;
            vector<char>checkVertical;
            for (int j = 0; j<board[i].size(); j++) { //horizontal loop

                
                if (i%3==0){
                checkBox.push_back(board[i][j]);
                checkBox.push_back(board[i+1][j]);
                checkBox.push_back(board[i+2][j]);
                }
                if (j%3==2) {
                    if (hasDupes(checkBox)) {
                    return false;
                    }
                    checkBox.clear();
                }
                checkHorizontal.push_back(board[i][j]);
                checkVertical.push_back(board[j][i]);
                
                }
                
                if (hasDupes(checkHorizontal)) {
                    return false;
                }
                if (hasDupes(checkVertical)){
                    return false;
            }
        }
        return true;
    }

    bool hasDupes (vector<char>& check) {
        unordered_set<char>dupes;
        for (int i = 0; i<check.size(); i++) {
            if (dupes.count(check[i])) {
                return true;
            } else if (check[i] != '.'){
                dupes.insert(check[i]);
            }
        }
        return false;
    }
};
