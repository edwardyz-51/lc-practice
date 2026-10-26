class FreqStack {
    int most_freq = 0;
    unordered_map<int,int>count;
    stack<int>st;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        count[val]++;
        if (count[val]>most_freq) most_freq = count[val];
    }
    
    int pop() {
        int ret;
        stack<int>undo;
        while (!st.empty()&&count[st.top()]!=most_freq){
            undo.push(st.top());
            st.pop();
        }
        ret = st.top();
        st.pop();
        count[ret]--;
        if (!count[ret])count.erase(ret);
        most_freq = 0;
        for (auto[_,c] : count) most_freq = max(most_freq,c);
        while (!undo.empty()){
            st.push(undo.top());
            undo.pop();
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */