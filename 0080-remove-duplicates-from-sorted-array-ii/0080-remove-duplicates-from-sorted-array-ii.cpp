class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++ ){
            mp[nums[i]] ++;
            if(mp[nums[i]] > 2) mp[nums[i]] = 2;
        }

        int count = 0;

        for(auto it: mp){
            count += it.second;
        }

        int i = 0;
        for(auto it: mp){

            int element = it.first;
            int dist = it.second;

            while(dist--){
                nums[i] = element;
                i++;
            }
        }
        return count;

    }
};