class MyStack {
public:
    queue<int> a;
    queue<int> b;
    bool a_out = false; // which stack will pop next time, true: a, false: b

    MyStack() {

    }
    
    void push(int x) {
        if (a_out) {
            b.push(x);
        } else {
            a.push(x);
        }
    }
    
    int pop() {
        if (a_out) {
            while (b.size() > 1) {
                int t = b.front();
                b.pop();
                a.push(t);
            }
            int ret = b.front();
            b.pop();
            a_out = !a_out;
            return ret;
        } else {
            while (a.size() > 1) {
                int t = a.front();
                a.pop();
                b.push(t);
            }
            int ret = a.front();
            a.pop();
            a_out = !a_out;
            return ret;
        }
    }
    
    int top() {
        if (a_out) {
            while (b.size() > 1) {
                int t = b.front();
                b.pop();
                a.push(t);
            }
            return b.front();
        } else {
            while (a.size() > 1) {
                int t = a.front();
                a.pop();
                b.push(t);
            }
            return a.front();
        }
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */