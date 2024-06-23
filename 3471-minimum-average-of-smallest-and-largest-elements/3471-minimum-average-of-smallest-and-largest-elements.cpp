class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());

        int n = nums.size();
        vector<double>ans;
        int count = 0;
        int left= 0;
        int right = n-1;
        while(count < n/2){
            double maxi = nums[left];
            double mini = nums[right];
            ans.push_back((maxi + mini) / 2);

            left++;
            right--;
            count++;
        }

        sort(ans.begin() , ans.end());

        return ans[0];

    }
};