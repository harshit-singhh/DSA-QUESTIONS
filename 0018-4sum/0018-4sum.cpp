class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int n = arr.size();
        
        for(int i = 0 ; i < n;  i++){
            for(int j = i+1 ; j < n ; j++){

                int k = j+1;
                int l = n-1;

                while(k < l){
                    long long sum = arr[i];
                    sum+= arr[j];
                    sum+=arr[k];
                    sum+=arr[l];

                    if(sum == target){
                        vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        while(k < l && arr[k] == arr[k-1]) k++;
                        while(k < l && arr[l] == arr[l+1]) l--;
                    }

                    else if(sum > target){
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                }
                while(j+1 != n && arr[j+1] == arr[j]) j++;
            }
            while(i+1 != n && arr[i+1] == arr[i]) i++;
        }

        return ans;
    }
    
};