class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mp;
        for(auto it : hand){
            mp[it]++;
        }

        for(auto it = mp.begin() ; it != mp.end();){
            if(it -> second != 0){
                for(int i = 0 ; i < groupSize ; i++){
                    if(mp[it->first+i] == 0 ) return false;
                    else if(mp[it -> first + i] > 0){
                        mp[it->first + i]--;
                    }
                }
            }
            else if(it -> second == 0)  it++;
           
        }

        return true;
    }
};