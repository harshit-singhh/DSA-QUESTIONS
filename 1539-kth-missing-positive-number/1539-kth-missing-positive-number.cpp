class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        unordered_set<int>st;

        for(auto it : arr){
            st.insert(it);
        }

        int missing_count = 0;

        int maxi = *max_element(arr.begin(), arr.end());

        for(int i = 1 ; i <= maxi ; i++){
            if(st.find(i) == st.end()){
                missing_count++;
                if(missing_count == k )return i;
            }
        }

        int extra = k - missing_count;
        return maxi + extra;

    }
};