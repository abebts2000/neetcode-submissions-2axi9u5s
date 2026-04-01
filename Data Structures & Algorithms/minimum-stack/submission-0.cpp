class MinStack {
    stack<int>stk,minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
      stk.push(val);
      if(minstk.empty() || minstk.top()>=val)
        minstk.push(val);
    }
    
    void pop() {
        if(minstk.top() == stk.top())
            minstk.pop();
        stk.pop();
    }
    
    int top() {
       return stk.top(); 
    }
    
    int getMin() {
        return minstk.top();
    }
};
