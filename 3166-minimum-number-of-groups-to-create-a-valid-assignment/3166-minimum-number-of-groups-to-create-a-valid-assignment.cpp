class Solution {
    private:
    void findPossible(unordered_map<int ,int >&possible , int x){

        possible[1]++;
        for(int i = 2 ; i <= x+1 ; i ++){

            int groups = x/(i-1);
            int rem = x%(i-1);

            if(rem <= groups) possible[i]++;
        }
    }
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        
        int n = nums.size();


        unordered_map<int,int>groupSize;
        unordered_map<int,int>possible;

        for(int i = 0 ; i < n ; i++){
            groupSize[nums[i]]++;
        }

        int groups = groupSize.size();

        for(auto it: groupSize){

            findPossible(possible, it.second);
        }

        int maxi = INT_MIN;

        for(auto it : possible){
            if(it.second == groups && it.first > maxi){
                maxi = it.first;
            }
        }

        int totalGroups = 0;
        for(auto it: groupSize){
            int e = it.second;
            totalGroups += (e % maxi == 0 ) ? e/maxi : e/maxi + 1;
        }

        return totalGroups;
        
    }
};