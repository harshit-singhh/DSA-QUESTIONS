class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int , int>mp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }


        priority_queue<pair<int,int>>q;
        for(auto it : mp){
            q.push({it.second , it.first});
        }

        vector<int>ans;
        while(k--){
            int elem = q.top().second;
            ans.push_back(elem);
            q.pop();
        }

        return ans;
    }
};