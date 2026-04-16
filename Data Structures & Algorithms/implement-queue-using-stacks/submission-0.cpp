class MyQueue {
    stack<int>stk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int size= stk.size();
        stack<int>tmp;
        while(!stk.empty())
        {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        auto top = stk.top();
        stk.pop();
        return top;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return stk.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */