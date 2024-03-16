class Solution {
public:
    string reverseWords(string s) {
        vector<string> stack;
        int top = 0;
        string tmp;
        s += ' ';
        // push in stack
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    stack.push_back(tmp);
                    ++top;
                    tmp = "";
                }
                continue;
            } else {
                tmp += s[i];
            }
        }
        // push out stack
        string out;
        --top;
        for (; top>0; --top) {
            out += stack[top];
            out += ' ';
        }
        out += stack[top];
        return out;
    }
};