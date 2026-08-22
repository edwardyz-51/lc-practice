class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>subset;
        vector<vector<string>>ans;
        dfs(0,0,s,subset,ans);
        return ans;
    }
    bool isPalindrome(int l, int r, string& s){
        while (l<r){
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(int l, int r, string s, vector<string>&subset, vector<vector<string>>&ans){
        if (r>=s.size()){
            if (l==r) ans.push_back(subset);
            return;
        }
        if (isPalindrome(l,r,s)){
            subset.push_back(s.substr(l,r-l+1));
            dfs(r+1,r+1,s,subset,ans);
            subset.pop_back();
        }
        dfs(l,r+1,s,subset,ans);
        
        
    }
};
