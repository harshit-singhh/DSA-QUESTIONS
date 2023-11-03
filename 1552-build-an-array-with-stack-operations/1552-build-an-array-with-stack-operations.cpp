class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        
        int maxi = *max_element(target.begin() , target.end());

        int index = 0;
        for(int i = 1 ; i<= maxi  ;i++){
            if(i != target[index]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else if(i == target[index]){
                ans.push_back("Push");
                index++;
            }
        }

        return ans;
    }
};