class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();

        double twt = customers[0][1];
        double prevEndingTime = customers[0][0] + customers[0][1];
        for(int i = 1 ; i < n ; i++){
            double waitingBczOfPrevPerson = prevEndingTime - customers[i][0];
            double gap = customers[i][0] - prevEndingTime;
            if(gap < 0) gap = 0;
            if(waitingBczOfPrevPerson <= 0) waitingBczOfPrevPerson = 0;
            double totalWaitingTimeForCurrPerson = waitingBczOfPrevPerson + customers[i][1];

            twt += totalWaitingTimeForCurrPerson;
            prevEndingTime += customers[i][1] + gap;
        }

        double finalans = double(twt)/n;

        return finalans;

    }
};