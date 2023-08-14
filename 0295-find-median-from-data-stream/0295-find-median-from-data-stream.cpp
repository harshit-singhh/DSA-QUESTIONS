class makeVector{
    public:
    priority_queue<int>max; // max heap
    priority_queue<int , vector<int> , greater<int>>min; // min heap
    
};


class MedianFinder {
public:
    makeVector* obj;
    MedianFinder() {
        obj = new makeVector();
    }
    
    void addNum(int num) {
        if(obj -> max.empty() || num < obj-> max.top()){
            obj->max.push(num);
        }
        else{
            obj->min.push(num);
        }
        //maintaining the size of both the heaps , the max heap should either have same elements as min heap
        // or the max heap should have just one element extra than min heap

        if(obj->max.size() > obj->min.size() + 1){
            obj->min.push(obj->max.top());
            obj->max.pop();
        }
        else if(obj -> min.size() > obj->max.size()){
            obj->max.push(obj->min.top());
            obj->min.pop();
        }
         
    }
    
    double findMedian() {
        if((obj->max.size() + obj->min.size())% 2 == 1){
            return obj->max.top();
        }
        else{
            double ans = (obj->max.top() + obj->min.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */