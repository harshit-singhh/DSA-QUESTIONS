class Solution {
public:

     bool ispossible(int shops , int toDonate , vector<int>arr , int size){
        if(toDonate == 0 ) return false;
        int CurrShop = 0;
        int i = 0;
        while(i < size){
            int ShopsDonated = arr[i]/toDonate;
            if(arr[i]%toDonate != 0 ) ShopsDonated+=1;
            CurrShop += ShopsDonated;
            i++;
        }

        if(CurrShop <= shops) return true;
        return false;

     }
    int minimizedMaximum(int n, vector<int>& arr) {
        int k = arr.size();
        int high = *max_element(arr.begin() , arr.end());
        int low = 0;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(ispossible(n , mid , arr , k)){
                high = mid-1;
                ans = min(ans , mid);
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};