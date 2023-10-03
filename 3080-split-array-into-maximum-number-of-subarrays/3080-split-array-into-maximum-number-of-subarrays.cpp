class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int val = 1048575;
        
        int n = nums.size();
        
        for(int i = 0; i < n ; i++){
            val = val&nums[i];
        }
        
        if(val != 0 ) return 1;
        
        int currAnd = 1048575;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            
            currAnd = currAnd&nums[i];
            if(currAnd == val){
                count++;
                currAnd = 1048575;
                
            }
        }
        
        return count;
    }
};