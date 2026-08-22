class WordDictionary {
public:
    vector<string> words;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words.push_back(word);
    }
    
    bool search(string word) {
        for (string s : words){
            int i = 0;
            if (s.length() == word.length()){
                while (i < word.length()){
                if (s[i]==word[i] || word[i] == '.') i++;
                else break;
            }
            if (i==word.length()) return true;
            } else continue;
        }
        return false;
    }
};
