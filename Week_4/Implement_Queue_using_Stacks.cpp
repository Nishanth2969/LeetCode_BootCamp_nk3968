class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int front;

public:
    MyQueue() { }

    void push(int x) {
        if (s1.empty()) {
            front = x;
        }
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top(); 
        s2.pop();           
        return ret;
    }

    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        return front;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

