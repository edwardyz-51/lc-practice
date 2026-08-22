class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        unordered_map<string, function<int(int,int)>> ops = {
        {"+", [](int a, int b){ return a + b; }},
        {"-", [](int a, int b){ return a - b; }},
        {"*", [](int a, int b){ return a * b; }},
        {"/", [](int a, int b){ return a / b; }}
    };
        stack<int> st;
        for (const string& t : tokens) {
            if (ops.count(t) == 0) {
                st.push(stoi(t));          // number
            } else {
                int b = st.top(); st.pop(); // right operand
                int a = st.top(); st.pop(); // left operand
                st.push(ops[t](a, b));
            }
        }
        return st.top();
    }
};
