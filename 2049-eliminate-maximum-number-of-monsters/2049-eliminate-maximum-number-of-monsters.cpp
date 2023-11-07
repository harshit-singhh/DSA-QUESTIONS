class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int count = 0, n = size(dist);

        //convert into time->needed to reach city 
        for(int i = 0; i < n; i++)
            if (dist[i] % speed[i] != 0) //d=5,s=3,time=1.6,after one minute->t = 0.6
                dist[i] = (dist[i]/speed[i])+1;  //adding +1 to account for this 0.6 
            else 
                dist[i] /= speed[i];
        
        //sort time, so we can eliminate monster that reaches first
        sort(dist.begin(),dist.end());

        for(int i = 0; i < n; i++){
            dist[i] -= i; //minutes away from city at ith minute
            if (dist[i] <= 0)//monster already at city
                break;
            count++;   //eliminate monster
        }

        /* //the above can also be written like this!!
        for(int time = 0; time < n; time++){
            if (dist[time] <= time) //monster reached city before or at time!
                break;
            count++;
        }
        */

        return count;
    }
};