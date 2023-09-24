class Solution {
    int solve(vector<int>&arr , int i , int j , int total , int turn){
        if(i > j ) return 0;

        if(turn){
            int fromFront = arr[i] + solve(arr, i+1 , j , total , 1-turn);
            int fromBehind = arr[j] + solve(arr, i , j-1 , total , 1-turn);

            return max(fromFront , fromBehind);
        }
        else{
            int fromFront = solve(arr, i+1 , j , total , 1-turn);
            int fromBehind = solve(arr, i , j-1 , total , 1-turn);

            return min(fromFront , fromBehind);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int i = 0 ;
        int j = n-1;

        int total = accumulate(nums.begin() , nums.end() , 0);
        int turn = 1;
        int ans  = solve(nums , i , j , total , turn);

        int player2 = total - ans;
        if(ans >= player2) return true;
        return false;
    }
};