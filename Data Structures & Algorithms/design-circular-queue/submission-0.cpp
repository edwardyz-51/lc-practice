class MyCircularQueue {
    int capacity;
    int size = 0;
    int * arr;
    int start = 0, back = 0;
public:
    MyCircularQueue(int k) : capacity(k){
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if (size==capacity) return false;
        arr[back] = value;
        back = (back+1) % capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (!size) return false;
        start = (start+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return size ? arr[start] : -1;
    }
    
    int Rear() {
        return size ? arr[(back - 1 + capacity) % capacity] : -1;
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */