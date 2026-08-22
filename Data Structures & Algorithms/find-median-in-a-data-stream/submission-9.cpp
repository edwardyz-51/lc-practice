class MedianFinder {
    priority_queue<int>bottomB; //max Heap
    priority_queue<int,vector<int>,greater<int>>topB; //min Heap
public:
    MedianFinder() {}
    void addNum(int num) {
        bottomB.push(num);

        if (!topB.empty() && bottomB.top() > topB.top()){
            topB.push(bottomB.top());
            bottomB.pop();
        }
        
        if (bottomB.size() == topB.size()+2){
            topB.push(bottomB.top());
            bottomB.pop();
        }
        else if (topB.size() == bottomB.size()+2){
            bottomB.push(topB.top());
            topB.pop();
        }
    }
    double findMedian() {
        if (bottomB.size()==topB.size()) return (bottomB.top()+topB.top())/2.0;
        else if (bottomB.size() == topB.size()+1) return bottomB.top();
        else return topB.top();
    }
};

