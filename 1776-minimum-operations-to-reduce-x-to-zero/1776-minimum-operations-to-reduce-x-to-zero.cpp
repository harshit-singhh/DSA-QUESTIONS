class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int operation = INT_MAX;

        int left = 0 , right = 0;

        int n = nums.size(); 

        int totalsum = accumulate(nums.begin() , nums.end() , 0);

        if(totalsum < x) return -1;
        int windowSum = totalsum - x;
        int currSum = 0;
        while(right  < n){
            currSum+=nums[right];

            while(currSum > windowSum){
                currSum -= nums[left];
                left++;
            }

            if(currSum == windowSum){
                operation = min(operation , (n - right - 1) + left);
            }
            right++;
        }

        if(operation == INT_MAX) return -1;
        return operation;
    }
};