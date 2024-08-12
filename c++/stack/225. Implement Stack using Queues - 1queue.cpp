class MyStack {
public:
    queue<int> que;

    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int s = que.size();
        int i = s;
        while (i > 1) {
            int t = que.front();
            que.pop();
            que.push(t);
            --i;
        }
        int ret = que.front();
        que.pop();
        return ret;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
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