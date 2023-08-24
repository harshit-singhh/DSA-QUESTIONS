class Solution {
    void solve( vector<int>&nums , set<vector<int>>&st , int index){
        if(index == nums.size()){
            st.insert(nums);
            return;
        }
        for(int i = index ; i < nums.size() ; i++){
            swap(nums[index] , nums[i]);
            solve(nums ,st ,index+1);
            swap(nums[index], nums[i]);
        }
    } 
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
         solve(nums, st , 0);
        vector<vector<int>>ans;

        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};