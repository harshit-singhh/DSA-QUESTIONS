class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        int n = arr.size();

        int bigger = arr[0];
        for(int i = 1 ; i < n ; i++){
            if(bigger > arr[i]){
                mp[bigger]++;

            }
            else if(bigger < arr[i]){
                bigger = arr[i];
                mp[bigger]++;
            }

            if(mp[bigger] == k ){
                return bigger;
            }

        }

        int maxi = *max_element(arr.begin() , arr.end());

        return maxi;



        
    }
};