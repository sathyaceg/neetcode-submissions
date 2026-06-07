class MinStack {
public:
    stack<int> s, min_stack;
    unordered_map<int, int> m;

    MinStack() {
        while (!min_stack.empty()) min_stack.pop();
        while (!s.empty()) s.pop();

        m.clear();
    }
    
    void push(int val) {
        stack<int> temp;        
        while (!min_stack.empty() && val > min_stack.top()) {
            int v = min_stack.top();
            temp.push(v);
            min_stack.pop();
        }
        min_stack.push(val);
        while (!temp.empty()) {
            min_stack.push(temp.top());
            temp.pop();
        }        
        s.push(val);

    }
    
    void pop() {
        int val = s.top();
        m[val]++;
        s.pop();
    }
    
    int top() {
        int a = s.top();
        return a;
    }
    
    int getMin() {
        cout << "MT: " << min_stack.top() << " MV: " << m[min_stack.top()] << '\n';
        while (!min_stack.empty() && m[min_stack.top()] > 0) {
            m[min_stack.top()]--;
            min_stack.pop();
        }
        int a = min_stack.top();
        return a;
    }
};
