class Solution {
    string make_key(const string& s){
        vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (i) key += ',';
                key += to_string(count[i]);
            }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) 
            res[make_key(s)].push_back(s);
        vector<vector<string>> result;
        for (const auto& [key,val] : res) 
            result.push_back(val);
        return result;
    }
};