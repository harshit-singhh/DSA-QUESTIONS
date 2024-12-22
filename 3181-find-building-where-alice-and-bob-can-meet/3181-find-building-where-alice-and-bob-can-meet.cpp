class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        
        
        
        unordered_map<int , vector<pair<int,int>>>mp;

        int n = h.size();
        int m = q.size();

        vector<int>ans(m);

        for(int i = 0 ; i < m ; i++){
            int a = q[i][0];
            int b = q[i][1];

            if(a == b ) ans[i] = a;
            else if(a > b && h[a] > h[b]) ans[i] = a;
            else if (b > a && h[b] > h[a]) ans[i] = b;
            else{

                int maxIndex = max(q[i][0] , q[i][1]);
                int maxValue = max(h[a], h[b]);

                mp[maxIndex].push_back({maxValue , i});
            }

        }

        

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>p;

        for(int i = 0 ; i <n ; i++){
            int val = h[i];

            while(!p.empty() && p.top().first < val){
                
                auto it = p.top();
                p.pop();
                int value = it.first;
                int index = it.second;

                ans[index] = i;


            }
            if(mp.count(i) == 1){
                for(int k = 0 ; k < mp[i].size(); k++){
                    p.push(mp[i][k]);
                }
            }
        }

        while(!p.empty()){
            auto it = p.top();
            p.pop();

            int index = it.second;
            ans[index] = -1;
        }

        return ans;

    }
};