class MinStack {
    stack<int> normal, mini;

   public:
    MinStack() {
    }

    void push(int val) {
        normal.push(val);
        if (mini.empty())
            mini.push(val);
        else
            mini.push(min(val, mini.top()));
    }

    void pop() {
        normal.pop();
        mini.pop();
    }

    int top() {
        return normal.top();
    }

    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */