class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>>p;
    int K;
    KthLargest(int k, vector<int>& nums) {
        // K = k;
        this -> K = k;
        for(auto it : nums){
            p.push(it);
            if(p.size() > k){
                p.pop();
            }
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size() > K) p.pop();
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */