// class Solution {
// public:
//     int maximumScore(vector<int>& nums, int k) {
        
        
//         int left = k;
//         int right = k;
//         int size = 1;
//         int n = nums.size();
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         while(left != 0 || right != n-1){
//             mini = min(mini , min(left , right));

//             int sum = mini*size;

//             maxi = max(maxi , sum);

//             if(left - 1 >= 0 && right +1 < n && nums[right+1] >= nums[left-1]){
//                 right++;
//                 size++;
//             }

//             else if(left - 1 >= 0 && right +1 < n && nums[right+1] < nums[left-1]){
//                 left--;
//                 size++;
//             }

//             else if(left == 0 && right+1 < n){
//                 right++;
//                 size++;
//             }
//             else if(right == n-1 && left-1 >= 0 ){
//                 left--;
//                 size++;
//             }

//         }

//         return maxi;

        
//     }
// };


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k];
        int mini = nums[k];
        int i = k;
        int j = k;
        int n = nums.size();

        while (i > 0 || j < n - 1) {
            if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i--;
            } else if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }

            mini = min(mini, min(nums[i], nums[j]));
            res = max(res, mini * (j - i + 1));
        }

        return res;
    }
};