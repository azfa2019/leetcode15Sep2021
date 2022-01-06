class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) maxHeap.push(num);
        else{
            if(num>maxHeap.top()) minHeap.push(num);
            else maxHeap.push(num);
        }
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()) return maxHeap.top();
        return (double)(maxHeap.top()+minHeap.top())/2.;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */