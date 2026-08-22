class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int count[26] = {0};
        for (char c : s) count[c-'a']++;
        int size = 0;
        unordered_map<char,int>window;
        for (int i = 0; i < s.size(); ++i){
            size++;
            if (window.count(s[i])) window[s[i]]--;
            else window[s[i]] = count[s[i]-'a'] - 1;
            if (window[s[i]]==0) window.erase(s[i]);
            if (window.empty()) {
                ans.push_back(size);
                size = 0;
            } 

        }
        return ans;
    }
};
