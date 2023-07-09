class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Code here
        vector<int>ans;
        
        map<int,int>m;  // storing element with frequency
        
        for(auto i:nums){
            m[i]++;
        }
        // create a max heap and store data frequency-->element which 
         //frequency highest store in ans;
        priority_queue<pair<int,int>>maxh;
        for(auto i:m){
            maxh.push({i.second,i.first});
        }
        while(k--){      // jab tak 0 na ho jae
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;

    
    }
};