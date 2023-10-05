class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
       int element1 = INT_MIN;
        int element2 = INT_MIN;
        int count1 = 0 ; 
        int count2 = 0;

        for(int i = 0 ; i < n ; i++){
            if(count1 == 0 && nums[i] != element2){
                count1++;
                element1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != element1){
                count2++;
                element2 = nums[i];
            }
            else if(nums[i] == element1) count1++;
            else if(nums[i] == element2) count2++;

            else {
                count1 --;
                count2 --;
            }
        }

        int elementcount1 =0;
        int elementcount2 = 0;
        vector<int>ans;

        for(int i = 0; i < n ; i++){
            if(nums[i] == element1){
                elementcount1 ++;
            }
            else if(nums[i] == element2) elementcount2++;
        }

        if(elementcount1 > n/3) ans.push_back(element1);
        if(elementcount2 > n/3) ans.push_back(element2);

        return ans;
    }
};