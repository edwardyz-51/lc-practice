class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize==1) return true;
        sort(hand.begin(),hand.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minHeap;
        for (int cur : hand){
            if (!minHeap.empty() && minHeap.top().first==cur){
                if (minHeap.top().second+1 < groupSize){
                    minHeap.push({cur+1,minHeap.top().second+1});
                }
                minHeap.pop();
            } else minHeap.push({cur+1,1});
        }
        return minHeap.empty();
    }
};
