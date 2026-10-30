class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> counts(26);
        for (char c : tiles) counts[c-'A']++;
        auto search = [&](auto&& self) -> int {
            int total = 0;
            for (int i = 0; i < 26; i++) {
                if (counts[i] > 0) {
                    counts[i]--;
                    total += 1 + self(self);
                    counts[i]++;
                }
            }
            return total;
        };
        return search(search);
    }
};
