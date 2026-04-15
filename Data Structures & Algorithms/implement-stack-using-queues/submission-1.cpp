class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
      int size = q.size()-1;
      while(size > 0)
      {
        q.push(q.front());
        q.pop();
        size--;
      }
      auto front = q.front();
      q.pop();
      return front;

    }
    
    int top() {
        int size = q.size()-1;
        while(size > 0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
        auto front = q.front();
        q.push(front);
        q.pop();
        return front;
    }
    
    bool empty() {
        return q.size() == 0;
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