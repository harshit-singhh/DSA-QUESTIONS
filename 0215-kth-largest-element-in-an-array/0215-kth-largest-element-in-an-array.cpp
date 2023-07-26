class comp{
    public:
    bool operator()(const int a , const int b){
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , comp> p;

        for(int i = 0 ; i < nums.size(); i ++){
            p.push(nums[i]);
            if(p.size() > k) p.pop();
        }

        return p.top();
    }
};