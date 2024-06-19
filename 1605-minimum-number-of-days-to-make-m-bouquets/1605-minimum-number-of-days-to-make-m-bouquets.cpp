class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1ll*m*k > 1ll*n) return -1;

        int low = *min_element(begin(bloomDay),end(bloomDay));
        int high = *max_element(begin(bloomDay),end(bloomDay));
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(isPossible(bloomDay,mid,m,k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }

    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt=0 , curr=0;
        for(int i=0 ; i<bloomDay.size() ; i++) {
            if(mid >= bloomDay[i]) {
                curr++;
            }
            else {
                cnt += curr/k;
                curr = 0;
            }
        }
        cnt += curr/k;
        return cnt>=m;
    }
};