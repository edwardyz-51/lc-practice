class Solution {
public:
    string multiply(string num1, string num2) {
        return to_string(1LL*stoi(num1)*stoi(num2));
    }
};
