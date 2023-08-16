class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int , vector<int> , greater<int>>p;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++) p.push(arr[i]);

        unordered_map<int,int>m;
        int prev = -1;
        int count = 0;
        while(!p.empty()){
            int element = p.top();
            if(element != prev){
                count++;
                m[element] = count;
            }
            prev = element;
            p.pop();
        }

        vector<int>ans(n);
        for(int i = 0 ; i  < n ; i++){
            ans[i] = m[arr[i]];
        }

        return ans;
    }
};