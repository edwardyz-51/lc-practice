class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int sz = min(word1.size(),word2.size()), i = 0;
        while(i < sz){
            ans.push_back(word1[i]);
            ans.push_back(word2[i++]);
        }
        while (i < word1.size()) ans.push_back(word1[i++]);
        while (i < word2.size()) ans.push_back(word2[i++]);
        return ans;
    }
};