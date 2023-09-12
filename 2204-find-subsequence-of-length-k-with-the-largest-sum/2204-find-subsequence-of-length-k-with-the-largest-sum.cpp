class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<int,int>>q;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[i] = nums[i];
        }

        for(auto it : mp){
            q.push({it.second , it.first});
        }
        vector<pair<int ,int>>vec;

        while(k--){
            vec.push_back({q.top().second , q.top().first});
            q.pop();
        }

        sort(vec.begin() , vec.end());
        vector<int>ans;

        for(auto it: vec){
            ans.push_back(it.second);
        }

        return ans;




    }
};