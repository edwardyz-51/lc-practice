class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;
        int reachableCount = 0;
        for (int i = 1; i < n; i++) {
            // index entering the valid jump window
            if (i - minJump >= 0 && reachable[i - minJump]) {
                reachableCount++;
            }

            // index leaving the valid jump window
            if (i - maxJump - 1 >= 0 &&
                reachable[i - maxJump - 1]) {
                reachableCount--;
            }

            if (s[i] == '0' && reachableCount > 0) {
                reachable[i] = true;
            }
        }

        return reachable[n - 1];
    }
};