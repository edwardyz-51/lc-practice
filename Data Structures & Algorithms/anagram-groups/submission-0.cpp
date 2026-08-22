class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp = strs;
        vector<vector<string>> ans;
        unordered_map<string,vector<int>>map;
        for (int i = 0; i < temp.size(); i++){
            sort(temp[i].begin(),temp[i].end());
            map[temp[i]].push_back(i);
        }
        for (auto a : map) {
            vector<string> anagrams;
            for (int i = 0; i<a.second.size(); i++) {
                anagrams.push_back(strs[a.second[i]]);
            }
            ans.push_back(anagrams);
        }
        return ans;



        
        

    }
};