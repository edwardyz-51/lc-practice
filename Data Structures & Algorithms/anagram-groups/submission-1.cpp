class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp = strs;
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>map;
        for (int i = 0; i < temp.size(); i++){
            sort(temp[i].begin(),temp[i].end());
            map[temp[i]].push_back(strs[i]);
        }
        for (auto a : map) {
            ans.push_back(a.second);
        }
        return ans;



        
        

    }
};