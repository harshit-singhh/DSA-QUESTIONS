class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();

        int count =0;

        unordered_map<char , int>mp;

        for(int i = 0 ; i < n ; i++){
            mp[s[i]]+=1;
        }

        priority_queue<int>q;

        for(auto it: mp){
            q.push(it.second);
        }

        while(q.size() > 1){
            int top1 = q.top();
            q.pop();
            int top2 = q.top();
            q.pop();

            if(top1 > top2){
                q.push(top2);
            }

            else if(top1 == top2){
                count++;
                top1--;
                if(top1 != 0) q.push(top1);
                q.push(top2);
            }
        }

        return count;
    }
};