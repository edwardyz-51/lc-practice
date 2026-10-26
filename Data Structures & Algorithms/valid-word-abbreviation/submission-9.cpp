class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        size_t i(0uz), j(0uz);
        while (i < word.size()&& j < abbr.size()){
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                int a = 0; 
                while (j < abbr.size() && isdigit(abbr[j])) 
                    a = (a * 10) + (abbr[j++] - '0');
                i += a; 
            } 
            else if (i >= word.size() || word[i++] != abbr[j++]) return false;    
        }
        return i == word.size() && j == abbr.size();
    }
};