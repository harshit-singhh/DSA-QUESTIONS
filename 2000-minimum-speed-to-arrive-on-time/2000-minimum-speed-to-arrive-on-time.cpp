class Solution {
    private:
    
    double find(int speed , vector<int>&dist){
        double ans = 0.0;

        int n = dist.size();

         for(int i=0;i<dist.size();i++){
            double val = (double)dist[i]/speed;
            if(i == n-1){
                ans+= val;
                break;
            }
            else{
                ans+=ceil(val);
            }
            
        }
        return ans;

    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;

        int ans = -1;
        while(low <= high){
            int mid = low + (high - low )/2;

            double time = find(mid,dist);

            if(time <= hour){
                ans = mid;
                high = mid -1;

            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};