class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize==1) return true;
        sort(hand.begin(),hand.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minHeap;
        for (int i = 0; i < hand.size();++i){
            if (!minHeap.empty() && minHeap.top().first==hand[i]){
                if (minHeap.top().second+1 < groupSize){
                    minHeap.push({hand[i]+1,minHeap.top().second+1});
                }
                minHeap.pop();
            } else {
                minHeap.push({hand[i]+1,1});
            }
        }
        return minHeap.empty();
    }
};
