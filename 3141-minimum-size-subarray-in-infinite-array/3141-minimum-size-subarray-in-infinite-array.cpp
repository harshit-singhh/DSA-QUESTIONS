class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        long long sum = 0;
        int size = nums.size();
        
        vector<int>cums;
        for(auto it: nums){
            cums.push_back(it);
        }
        for(auto it: nums){
            cums.push_back(it);
        }

        int n = cums.size();
        sum = accumulate(cums.begin() , cums.end() , 0LL);
        long long numsum = sum/2;

        int count = 0;
        if(target == numsum )return size;
        while(target > numsum){
            target -= numsum;
            count+=size;
            if(target == numsum){
                count+=size;
                return count;
            }
        }

        int left = 0 , right = 0;
        int minLen = INT_MAX;
       
        int currSum = 0;
        while(right < n){
            currSum += cums[right];
            
            while(currSum > target){
                currSum -= cums[left];
                
                left++;
            }

            if(currSum == target){
                minLen = min(minLen , right - left + 1);
            }

            right++;

        }

        if(minLen == INT_MAX) return -1;
        count+= minLen;

        return count;

        
    }
};