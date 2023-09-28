class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int solve(vector<int>&arr1 , int n , vector<int>&arr2 , int m , int index , int prev){
        if(index == n) return 0;

        if (memo.count(index) && memo[index].count(prev)) {
            return memo[index][prev]; // Return memoized result if available
        }
        int mini = 1e9;
        int j=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(j != m){
            int replacement = 1 + solve(arr1 , n , arr2 , m , index+1 , arr2[j]);

            mini = min(mini , replacement);
        }

        if(arr1[index] > prev){
            int replacement = 0 + solve(arr1 ,n, arr2 , m , index+1 , arr1[index] );
            mini = min(mini , replacement);
        }

        return memo[index][prev] = mini;
    } 
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin() , arr2.end());
        int ans = solve(arr1 , n , arr2 , m , 0 , -1);
        return ans == 1e9 ? -1 : ans;
    }
};