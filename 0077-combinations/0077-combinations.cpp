class Solution {
    private:
    void solve(int n , int k , int index , vector<int>&temp , vector<vector<int>>&ans){

        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        if(index == n+1){
            if(temp.size() == k){
                ans.push_back(temp);
                return;
            }
            return;
        }

        temp.push_back(index);
        solve(n , k , index+1, temp , ans);
        temp.pop_back();
        solve(n , k , index+1 , temp ,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;

        solve(n , k , 1 , temp , ans);

        return ans;
    }
};