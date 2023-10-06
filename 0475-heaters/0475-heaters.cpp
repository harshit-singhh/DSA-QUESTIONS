class Solution {

    int findClosest(vector<int>&heaters , int n , int house){

        int low = 0;
        int high = n-1;

        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            int difference = abs(house - heaters[mid]);
            if(heaters[mid] == house) return 0;
            if(heaters[mid] > house){
                ans = min(ans , difference);
                high = mid - 1;

            }
            else{
                ans = min(ans , difference);
                low = mid+1;
            }
        }

        return ans;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int low = 0;
        int n = houses.size();

        sort(heaters.begin() , heaters.end());
        int m = heaters.size();

        int high = n-1;

        int closest = INT_MIN;

        for(int i = 0 ; i < n ; i++){

            int closestDistance = findClosest(heaters , m , houses[i]);
            closest = max(closest , closestDistance);
        }

        return closest;


    }
};