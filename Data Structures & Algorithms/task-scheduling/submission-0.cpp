class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for (char t : tasks) {
            count[t-'A']++;
        }
        priority_queue<int>maxHeap;
        for (int k : count){
            if (k!=0) maxHeap.push(k);
        }
        int time = 0;
        queue<pair<int,int>>queue;
        while(!maxHeap.empty() || !queue.empty()){
            time++;
            if (!maxHeap.empty()){
                int temp = maxHeap.top()-1;
                maxHeap.pop();
                if (temp>0) queue.push({temp,time});
            }
            if (!queue.empty() && time >= queue.front().second + n){
                maxHeap.push(queue.front().first);
                queue.pop();
            }
            
        }
        return time;
    }
};
