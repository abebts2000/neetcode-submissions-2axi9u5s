class FreqStack {
public:
    unordered_map<int,int>dict;
    priority_queue<tuple<int,int,int>>hp;
    int indx;
    FreqStack(): indx(0) {
        
    }
    
    void push(int val) {
        dict[val]++;
        hp.push({dict[val],indx++,val});
    }
    
    int pop() {
        auto [cnt,indx,val] = hp.top();
        hp.pop();
        dict[val]--;
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */