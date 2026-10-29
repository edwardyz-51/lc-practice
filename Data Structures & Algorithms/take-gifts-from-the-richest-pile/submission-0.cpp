class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        for (int t = 0; t < k; t++) {
            int n = pq.top(); pq.pop();
            pq.push((int)floor(sqrt(n)));
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
        return sum;
    }
};