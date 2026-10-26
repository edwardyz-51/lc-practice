class FreqStack {
    unordered_map<int, int> numToFrequency;
    unordered_map<int, stack<int>> frequencyToNumStack;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        numToFrequency[val]++;
        int freq = numToFrequency[val];
        if(freq > maxFreq){
            maxFreq = freq;
        }
        frequencyToNumStack[freq].push(val);
    }
    
    int pop() {
        auto& st = frequencyToNumStack[maxFreq];
        int num = st.top();
        st.pop();
        numToFrequency[num]--;
        if(st.empty()){
            maxFreq--;
        }
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */