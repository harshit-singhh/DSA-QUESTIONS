class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){

                string a = to_string(nums[i]);
                string b = to_string(nums[j]);

                string append1 = a+b;
                string append2 = b+a;

                if(append2 > append1) swap(nums[j] , nums[i]);
            }
        }

        string ans = "";

        for(int i = 0 ; i< n ; i++){
            ans += to_string(nums[i]);
        }
        bool allzero = true;

        for(auto it: ans){
            if(it != '0'){
                allzero = false;
                break;
            } 
        }

        if(allzero) return "0";
        return ans;
    }
};