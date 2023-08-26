bool comp(vector<int> a , vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin() , pairs.end() , comp);

        int n = pairs.size();
        if(n == 1) return 1;

        int count = 1;
        int i = 1;

        vector<int>currpair = pairs[0];

        while(i < n){
            if(currpair[1] < pairs[i][0]){
                count++;
                currpair = pairs[i];
            }
            i++;
        }
        return count;
    }
};