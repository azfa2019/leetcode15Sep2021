class MedianFinder {
  priority_queue<int>maxHeap;
  priority_queue<int,vector<int>,greater<>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(maxHeap.empty()) {
        maxHeap.push(num);
        return;
      }
      if(num>maxHeap.top()) minHeap.push(num);
      else maxHeap.push(num);
      if(minHeap.size()>maxHeap.size()) {
        int tmp=minHeap.top();
        minHeap.pop();
        maxHeap.push(tmp);
      }
      if(maxHeap.size()>minHeap.size()+1){
        int tmp=maxHeap.top();
        maxHeap.pop();
        minHeap.push(tmp);
      }
    }
    
    double findMedian() {
      if(minHeap.size()==maxHeap.size()) return double(minHeap.top()+maxHeap.top())/2.0;
      return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */