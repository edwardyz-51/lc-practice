class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i : stones) maxHeap.push(i);
        while (maxHeap.size()>1){
            int top = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();
            if (top>top2) maxHeap.push(top-top2);
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
