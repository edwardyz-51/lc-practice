class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> queue;
        for (int i : nums) queue.push(i);
        for (int i = 0; i < k-1; ++i){
            queue.pop();
        }
        return queue.top();
    }
};
