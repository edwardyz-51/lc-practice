class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char>stack;
        for (char c:s){
            if (map.find(c)!=map.end()){
                if (stack.empty() || stack.top()!=map[c]) return false;
                stack.pop();
            }
            if (map.find(c)==map.end()) stack.push(c);
        }
        return stack.empty();
    }
};
