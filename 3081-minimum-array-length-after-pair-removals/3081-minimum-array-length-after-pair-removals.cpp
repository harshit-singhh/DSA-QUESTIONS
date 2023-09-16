class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]+=1;
        }
        
        priority_queue<int>q;
        
        for(auto it: mp){
            q.push(it.second);
        }
        
        int size = q.size();
        
        while(size > 1){
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();
            
            
            t1--;
            t2--;
            if(t1) q.push(t1);
            else size--;
            if(t2) q.push(t2);
            else size--;
            
        }
        
        if(q.size() == 1) return q.top();
        else return 0;
    }
};