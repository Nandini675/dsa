class MedianFinder {
public:
 priority_queue<int>maxheap;// left side of median contain element which r <= median, to get the lagrest el on lhs
 priority_queue<int, vector<int>,greater<int>>minheap;//// rytt side of median contain element which r >= median
 //to get smallest ele fron rhs
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        maxheap.push(num);
        //  check if all the el of maxheap <minheap
        if(!minheap.empty()&& !maxheap.empty()&& maxheap.top()> minheap.top()){
             minheap.push(maxheap.top());
             maxheap.pop();
        }
        // difference in the size of both heap should can be 1(if n= odd) or 0 ( if n is even)not other than this
         if( maxheap.size()> minheap.size()+1){
   minheap.push(maxheap.top());
   maxheap.pop();
         }
         if( maxheap.size()+1<minheap.size()){
   maxheap.push(minheap.top());
   minheap.pop();
         }

    }
    
    double findMedian() {
        // agr n odd hua toh jis hap mai bhi el jyada hai uska top = median
        if(minheap.size()>maxheap.size()){
             return minheap.top();
        }
        if(minheap.size()<maxheap.size()){
             return maxheap.top();
        }
        else {
             return (minheap.top()+ maxheap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */