class MedianFinder {
public:
    priority_queue<int,vector<int>, greater<>>minQ;
    priority_queue<int,vector<int>>maxQ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxQ.empty() || num <= maxQ.top()) {
            maxQ.push(num);
        } else {
            minQ.push(num);
        }

        if (maxQ.size() > minQ.size() + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
        } else if (minQ.size() > maxQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }

    }
    
    double findMedian() {
        
        return minQ.size() == maxQ.size()? (double)(minQ.top()+maxQ.top())/2 : maxQ.top();

    }
};
