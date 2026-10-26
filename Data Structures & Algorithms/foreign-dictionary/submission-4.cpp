class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        array<int,26> degrees{};
        int count = 0;
        vector<vector<bool>>adj(26,vector<bool>(26,0));
        array<bool,26> seen{};
        //create a graph of some sort for each word.
        for (const string& word : words)
            for (char c : word){
                if (!seen[c-'a'])seen[c - 'a'] = true, count++;
            }
            
        for (size_t i(1uz); i < words.size(); ++i){
            const string& word = words[i], word2 = words[i-1];
            size_t sz = min(word.size(),word2.size());
            for (size_t idx(0uz); idx < sz; ++idx){
                int cur = word[idx]-'a', prev = word2[idx]-'a';
                seen[cur] = true, seen[prev] = true;
                if (cur==prev){
                    if (idx + 1 == sz && word.size() < word2.size()) return ""; 
                    continue;
                } 
                if (!adj[prev][cur]) {
                    adj[prev][cur] = true;
                    degrees[cur]++;
                }
                break;
            }
        }
        queue<char>q;
        for (size_t i(0uz); i < 26; ++i)
            if (seen[i] && !degrees[i]) q.push(i+'a');
        string ans;
        while (!q.empty()){
            char c = q.front();
            q.pop();
            ans.push_back(c);
            for (int i = 0; i < 26; ++i) {
                if (!adj[c-'a'][i]) continue;
                degrees[i]--;
                if (!degrees[i]) q.push(i+'a');
            }
        }
        return ans.size() == count ? ans : "";


    }
};


