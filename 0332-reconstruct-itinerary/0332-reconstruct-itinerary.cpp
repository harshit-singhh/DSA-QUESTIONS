class Solution {
    bool solve(map<string ,vector<string>>&mp , vector<string>&ans , vector<string>temp,  string node , int n){
       temp.push_back(node);
       if(temp.size() == n+1){
           ans = temp;
           return true;
       }
       
    //    if(mp.find(node) == mp.end()){
    //        return false;
    //    }

       vector<string>&str = mp[node];
       for(int i = 0 ; i < str.size() ; i++){
           string to_visit = str[i];
           str.erase(str.begin() + i);
           if(solve(mp , ans , temp , to_visit , n)) return true;
           str.insert(str.begin() + i , to_visit);
       }

        temp.pop_back();
        return false;

    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string , vector<string>> mp;

        int n = tickets.size();

        for(auto &it: tickets){
            mp[it[0]].push_back(it[1]);
        }

        for(auto &it: mp){
            sort(it.second.begin() , it.second.end());
        }

        vector<string>temp;
        vector<string>ans;
   

        solve(mp , ans ,temp ,  "JFK" , n);

        return ans;
    }
};