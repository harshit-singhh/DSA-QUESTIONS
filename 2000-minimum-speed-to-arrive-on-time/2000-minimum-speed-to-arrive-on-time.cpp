class Solution {
    private:
    
    double find(int value , vector<int>&dist){
        double ans = 0.0;

        int n = dist.size();

         for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/value;
            if(i!=dist.size()-1)
            ans=ans+ceil(d);
            else
            ans+=d;
            
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