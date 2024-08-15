class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;
        st.push(stoi(tokens[0]));
        for (int i=1; i<tokens.size(); ++i) {
            if (!isOperator(tokens[i])) {
                st.push(stoi(tokens[i]));
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(Operate(b, a, tokens[i]));
            }
        }
        return st.top();
    }
    bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        return false;
    }
    int Operate(int a, int b, string op) {
        int res = 0;
        switch (op[0]) {
            case '+': res = a + b;
                      break;
            case '-': res = a - b;
                      break;
            case '*': res = a * b;
                      break;
            case '/': res = a / b;
                      break;
        }
        return res;
    }
};