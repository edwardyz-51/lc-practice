class Solution {
    vector<vector<char>>map = {{},{},{'a','b','c'},{'d','e','f'},
        {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},
        {'t','u','v'},{'w','x','y','z'}};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string>ans;
        string subset;
        

        dfs(0,0,subset,digits,ans);
        return ans;
    }
    void dfs(int index, int offset, string& subset, string& digits, vector<string>&ans){
        int i = digits[index]-'0';
        if ((i != 7) && (i != 9) && offset==3) return;
        else if (offset==4) return;
        if (index == digits.size()){
            ans.push_back(subset);
            return;
        } 
        subset.push_back(map[i][offset]);
        dfs(index+1,0,subset,digits,ans);
        subset.pop_back();
        dfs(index, offset+1,subset,digits,ans);
    }
};
