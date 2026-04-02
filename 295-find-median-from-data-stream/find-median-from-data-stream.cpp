class MedianFinder {
public:
    priority_queue<int> max_ele;
    priority_queue<int,vector<int>,greater<int>> min_ele;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_ele.push(num);

        min_ele.push(max_ele.top());
        max_ele.pop();
        
        if(min_ele.size()>max_ele.size()){
            max_ele.push(min_ele.top());
            min_ele.pop();
        }
        
    }
    
    double findMedian() {
         if(max_ele.size() > min_ele.size()){
            return max_ele.top();
        }else{
            return (min_ele.top()+max_ele.top())/2.0;
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */