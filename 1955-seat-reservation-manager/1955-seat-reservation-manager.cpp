class SeatManager {
public:
    int seatPointer = 0;
    priority_queue<int,vector<int>, greater<int>>q;
    SeatManager(int n) {
        
    }
    
    int reserve() {

        if(!q.empty()){
            int ans = q.top();
            q.pop();
            return ans;
        }

        seatPointer++;
        return seatPointer;

        
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */