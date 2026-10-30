class Solution {
public:
    int numTilePossibilities(string tiles) {
        int counts[26]={0};
        for (char c : tiles) counts[c-'A']++;
        auto search = [&](this auto& self) -> int {
            int total = 0;
            for (int i = 0; i < 26; i++) {
                if (counts[i] > 0) {
                    counts[i]--;
                    total += 1 + self();
                    counts[i]++;
                }
            }
            return total;
        };
        return search();
    }
};
