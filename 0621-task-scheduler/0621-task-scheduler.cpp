class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26,0);
        for(auto it : tasks){
            freq[it - 'A']++;
        }

        sort(freq.begin() , freq.end());
        int maxFreq = freq[25];

        int gaddha = freq[25]-1;
        int idleSpot = gaddha*n;

        for(int i = 24 ; i>= 0 ; i--){
            idleSpot -= min(freq[i] , gaddha);
        }
        
        if(idleSpot > 0) return tasks.size() + idleSpot;
        else return tasks.size();
    }
};