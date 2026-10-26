class Solution { 
public: 
    bool validWordAbbreviation(string word, string abbr) { 
        size_t i(0uz), j(0uz); 
        while (i < word.size() && j < abbr.size()){ 
            if (abbr[j] == '0') return false; // Fix 1: Reject leading zeros
            
            if (isdigit(abbr[j])) {
                int a = 0; 
                while (j < abbr.size() && isdigit(abbr[j])) {
                    a = (a * 10) + (abbr[j++] - '0'); // Note: fixed + '0' to - '0'
                }
                i += a; 
            } else {
                if (i >= word.size() || word[i++] != abbr[j++]) return false; 
                // Fix 2: Removed the redundant trailing j++; from here
            }
        } 
        return i == word.size() && j == abbr.size(); // Fix 3: Ensure both strings are fully consumed
    } 
};
