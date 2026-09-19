class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>prefix(n , 0);
        vector<int>suffix(n , 0);

        int maxi = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , height[i]);
            prefix[i] = maxi;
        }

        maxi = INT_MIN;
        
        for(int i = n-1 ; i >= 0 ; i--){
            maxi =  max(maxi , height[i]);
            suffix[i] = maxi;
        }

        int water = 0;
        for(int i = 0 ; i < n ; i ++){

            water += min(prefix[i] , suffix[i]) - height[i];
        }
        return water;
    }
};