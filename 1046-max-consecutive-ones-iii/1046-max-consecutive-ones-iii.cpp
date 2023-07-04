class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 , right = 0 , zeroCount = 0; // apne ko esi window leke chalni he jisme max k zeroes ho. kyuki unhi
        // k zeros ko flip karke, hum 1 bna denge and max sum find kar lenge
        
        int maxlength = 0;

        int n = nums.size();
        
        while(right<n){
            
            if(nums[right] == 0) zeroCount++;
            
            while(zeroCount > k){
                if(nums[left] == 0)
                    zeroCount--;
                        
                left++;
            }
                
            int length = right-left+1;
            
            maxlength = max(maxlength,length);
            
            right++;
                
        }
        
        return maxlength;
    }
};