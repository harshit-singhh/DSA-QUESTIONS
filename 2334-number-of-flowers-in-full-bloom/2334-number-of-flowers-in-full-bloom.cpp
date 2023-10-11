class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();

        vector<int>startTime(n , 0);

        vector<int>endTime(n , 0);

        for(int i = 0 ; i < n ; i++){
            startTime[i] = flowers[i][0];
        }

        for(int i = 0 ; i < n ; i++){
            endTime[i] = flowers[i][1];
        }

        sort(startTime.begin() , startTime.end());
        sort(endTime.begin() , endTime.end());


        int size = people.size();

        vector<int>ans(size , -1);
        for(int i = 0 ; i < size ; i++){

            auto it = upper_bound(startTime.begin() , startTime.end() , people[i]);

            int bloomed = it - startTime.begin();

            auto ti = lower_bound(endTime.begin() , endTime.end() , people[i]);

            int dead = ti - endTime.begin();

            ans[i] = bloomed - dead;
        }

        return ans;
    }
};