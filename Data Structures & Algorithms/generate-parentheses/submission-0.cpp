class Solution {
public:
    bool isValid(const string& s){
        int open = 0;
        for (char c : s){
            if (c == '('){
                open++;
            } else {
                open--;
                if (open < 0) return false;
            }
        }
        return open == 0;

    }

    void dfs (string s, vector<string>& res, int n){
        if (s.length() == 2 * n){
            if (isValid(s)) res.push_back(s);
            return;
        }
        dfs(s + '(', res, n);
        dfs(s + ')', res, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs ("",res,n);
        return res;
    }
};
