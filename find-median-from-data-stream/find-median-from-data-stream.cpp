class MedianFinder {
    priority_queue<int,vector<int>,greater<>> minHeap;
    priority_queue<int>maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        if(num<=maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        if(minHeap.size()>maxHeap.size()) {
            int tmp=minHeap.top();minHeap.pop();
            maxHeap.push(tmp);
        }
        if(minHeap.size()+1<maxHeap.size()) {
            int tmp=maxHeap.top();maxHeap.pop();
            minHeap.push(tmp);
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()) return maxHeap.top();
        else return double(minHeap.top()+maxHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */