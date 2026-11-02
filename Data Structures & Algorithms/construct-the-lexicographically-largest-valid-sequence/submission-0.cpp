class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        auto dfs = [&](this auto&& self, int i) -> bool {
            if (i == ans.size()) return true;
            if (ans[i] != 0) return self(i + 1);
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                int j = i + num;
                if (num > 1 &&
                    (j >= ans.size() || ans[j] != 0))
                    continue;
                ans[i] = num;
                if (num > 1) ans[j] = num;
                used[num] = true;
                if (self(i + 1)) return true;
                ans[i] = 0;
                if (num > 1) ans[j] = 0;
                used[num] = false;
            }
            return false;
        };
        dfs(0);
        return ans;
    }
};