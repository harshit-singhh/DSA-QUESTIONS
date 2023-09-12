class Solution {
    int solve(vector<int>&nums , int index , int n , bool&canrob , map<pair<int , bool> , int>&mp){
        if(index ==0 && canrob == true) return nums[0];
        if(index == 0 && canrob == false) return 0;
        if(index < 0) return 0;
        
        if(mp.find({index , canrob}) != mp.end()) return mp[{index , canrob}];
        if(index == n-1) canrob = false;
        int pick = nums[index] + solve(nums , index-2 , n , canrob , mp);
        if(index == n-1) canrob = true;
        int notpick = 0 + solve(nums, index-1 , n , canrob ,mp);

        return mp[{index , canrob}] = max(pick , notpick);
    }
public:
    int rob(vector<int>& nums) {
        bool canrob = true;
        int n = nums.size();
        map<pair<int , bool> , int>mp;
        return solve(nums , n-1 , n , canrob, mp);
    }
};