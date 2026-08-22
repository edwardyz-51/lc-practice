class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>sorted;
        for (string &s : strs){
            string key = s;
            sort(key.begin(),key.end());
            sorted[key].push_back(s);
        }
        vector<vector<string>>ans;
        for (auto& [_,v] : sorted) ans.push_back(v);
        return ans;
    }
};