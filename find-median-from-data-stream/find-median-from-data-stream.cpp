class MedianFinder {
  priority_queue<int,vector<int>,greater<>>minHeap;
  priority_queue<int>maxHeap;

  public:
  MedianFinder() {

  }

  void addNum(int num) {
    if(maxHeap.size()==0||num<maxHeap.top() ){
      maxHeap.push(num); 
      if(maxHeap.size()>minHeap.size()+1){
        int tmp=maxHeap.top();
        maxHeap.pop();
        minHeap.push(tmp);
      }
    } else{
      minHeap.push(num);
      if(minHeap.size()>maxHeap.size()) {
        int tmp=minHeap.top();
        minHeap.pop();
        maxHeap.push(tmp);
      }
    }
  }

  double findMedian() {
    if(maxHeap.size()==minHeap.size()) 
      return ((double)minHeap.top()+maxHeap.top())/2.0;
    else 
      return (double)maxHeap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */