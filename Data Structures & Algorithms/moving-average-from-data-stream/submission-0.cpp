class MovingAverage {
    deque<int>dq;
    double sum_;
    int size_;
public:
    MovingAverage(int size) {
       size_ = size;
       sum_ = 0.0; 
    }
    
    double next(int val) {
        sum_ += val;
        dq.push_back(val);
        if(dq.size() > size_)
        {
            sum_-=dq.front();
            dq.pop_front();
            
        }
       return sum_/dq.size();

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
