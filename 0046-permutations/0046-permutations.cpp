class Solution {
    void solve( vector<int>&nums , vector<int> temp , vector<vector<int>>&ans , int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index ; i < nums.size() ; i++){
            swap(nums[index] , nums[i]);
            solve(nums , temp , ans ,index+1);
            swap(nums[index], nums[i]);
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;

        solve(nums, temp , ans , 0);
        return ans;
    }
};